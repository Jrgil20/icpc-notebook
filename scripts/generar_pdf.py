#!/usr/bin/env python3
"""Arma el notebook imprimible (PDF, carta horizontal, 2 columnas) a partir de los README del repo.

Cada linea "Codigo: [`archivo`](ruta)" de un README se reemplaza por el contenido real del archivo,
asi el PDF siempre lleva exactamente el codigo probado.

Requisitos:  pip install markdown pygments   y   Google Chrome o Chromium (para imprimir a PDF).
Uso:         python3 scripts/generar_pdf.py            -> notebook/notebook.pdf
             python3 scripts/generar_pdf.py --html     -> solo notebook/notebook.html
"""
import os, re, sys, shutil, subprocess
import markdown

RAIZ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ORDEN = ["00-base/README.md", "01-sintaxis/README.md", "01-sintaxis/python.md", "01-sintaxis/cpp.md",
         "02-basicos/README.md", "03-grafos/README.md", "04-estructuras/README.md", "05-strings/README.md",
         "06-matematica/README.md", "07-geometria/README.md", "08-esqueletos/README.md", "09-estrategia/README.md"]

def lenguaje(path):
    return {".cpp": "cpp", ".py": "python", ".sh": "bash", ".h": "cpp"}.get(os.path.splitext(path)[1], "text")

def expandir_codigo(md, carpeta):
    def rep(m):
        bloques = []
        for ruta in re.findall(r"\]\(([^)]+)\)", m.group(0)):
            p = os.path.normpath(os.path.join(carpeta, ruta))
            if os.path.isfile(p):
                bloques.append(f"```{lenguaje(p)}\n{open(p, encoding='utf-8').read().rstrip()}\n```")
        return "\n\n".join(bloques) if bloques else m.group(0)
    return re.sub(r"^Código: .*$", rep, md, flags=re.M)

def bajar_titulos(md):
    # '# X' -> '## X', '## X' -> '### X' (fuera de bloques de codigo)
    out, en_codigo = [], False
    for l in md.split("\n"):
        if l.startswith("```"): en_codigo = not en_codigo
        if not en_codigo and l.startswith("#"): l = "#" + l
        out.append(l)
    return "\n".join(out)

CSS = """
@page { size: letter landscape; margin: 9mm 8mm 10mm 8mm; }
body { font-family: 'DejaVu Sans', Arial, sans-serif; font-size: 7.2pt; line-height: 1.22; column-count: 2; column-gap: 5mm; column-rule: 0.4pt solid #999; margin: 0; }
h1 { column-span: all; font-size: 13pt; margin: 0 0 2mm; border-bottom: 1.5pt solid #000; }
h2 { font-size: 9.5pt; background: #000; color: #fff; padding: 0.6mm 1.5mm; margin: 2.5mm 0 1mm; break-after: avoid; }
h3 { font-size: 8pt; border-bottom: 0.6pt solid #000; margin: 1.6mm 0 0.6mm; break-after: avoid; }
p { margin: 0.8mm 0; }
table { border-collapse: collapse; width: 100%; margin: 0.8mm 0 1.5mm; font-size: 6.6pt; }
th { background: #ddd; text-align: left; } th, td { border: 0.4pt solid #888; padding: 0.3mm 0.8mm; vertical-align: top; }
tr { break-inside: avoid; }
code { font-family: 'DejaVu Sans Mono', monospace; font-size: 6.4pt; }
.codehilite { border-left: 1.2pt solid #000; background: #f4f4f4 !important; padding: 0.5mm 1mm; margin: 0.5mm 0 1.2mm; break-inside: avoid; }
.codehilite pre { margin: 0; white-space: pre-wrap; word-break: break-word; font-size: 6.4pt; line-height: 1.17; background: none !important; }
ol, ul { margin: 0.5mm 0; padding-left: 4mm; } li { margin: 0.2mm 0; }
a { color: #000; text-decoration: none; }
"""

def main():
    partes = ["# ICPC Notebook — plantillas probadas (Python + C++)\n"]
    for rel in ORDEN:
        p = os.path.join(RAIZ, rel)
        md = open(p, encoding="utf-8").read()
        partes.append(bajar_titulos(expandir_codigo(md, os.path.dirname(p))))
    html_body = markdown.markdown("\n\n".join(partes), extensions=["tables", "fenced_code", "codehilite"],
                                  extension_configs={"codehilite": {"guess_lang": False, "noclasses": True, "pygments_style": "bw"}})
    os.makedirs(os.path.join(RAIZ, "notebook"), exist_ok=True)
    html_path = os.path.join(RAIZ, "notebook", "notebook.html")
    open(html_path, "w", encoding="utf-8").write(
        f"<!DOCTYPE html><html lang='es'><head><meta charset='utf-8'><title>ICPC Notebook</title><style>{CSS}</style></head><body>{html_body}</body></html>")
    if "--html" in sys.argv:
        print("HTML listo:", html_path); return
    chrome = next((shutil.which(c) for c in ["google-chrome", "chromium", "chromium-browser", "chrome"] if shutil.which(c)), None)
    if not chrome:
        print("No encontre Chrome/Chromium. Abre", html_path, "en el navegador e imprime a PDF (horizontal, sin margenes extra)."); return
    pdf_path = os.path.join(RAIZ, "notebook", "notebook.pdf")
    subprocess.run([chrome, "--headless", "--no-sandbox", "--disable-gpu", "--no-pdf-header-footer",
                    f"--print-to-pdf={pdf_path}", html_path], check=True, capture_output=True)
    print("PDF listo:", pdf_path)

if __name__ == "__main__":
    main()

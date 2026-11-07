from itertools import groupby

def runs(s):
    """'aaabcc' -> [('a', 3), ('b', 1), ('c', 2)]"""
    return [(c, len(list(g))) for c, g in groupby(s)]

def collapse(s):
    """'aaabcc' -> 'abc' (quita repetidos CONSECUTIVOS)"""
    return "".join(c for c, _ in groupby(s))

if __name__ == "__main__":
    assert runs("aaabcc") == [("a", 3), ("b", 1), ("c", 2)]
    assert collapse("ddddaata") == "data"
    print("rachas.py OK")

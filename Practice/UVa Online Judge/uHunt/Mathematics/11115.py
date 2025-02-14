while True:
    _in = input().split()
    if (_in[0] == "0" and _in[1] == "0"):
        break
    print(int(_in[0]) ** int(_in[1]))

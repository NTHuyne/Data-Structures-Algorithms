s = str(input())

def format(s):
    if(len(s)>=3):
        if s.endswith("ing"):
            s = s + "ing"
        else:
            s = s + "ly"
    return s

print(format(s))
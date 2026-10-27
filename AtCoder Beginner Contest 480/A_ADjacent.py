s = [input(), input()]

adj1 = {s[0][0], s[1][1]}
adj2 = {s[0][1], s[1][0]}

if 'A' in adj1 and 'D' in adj1 or 'A' in adj2 and 'D' in adj2:
    print('No')
else:
    print('Yes')
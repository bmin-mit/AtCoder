n, m = map(int, input().split())

names = [input() for _ in range(n)]
votes = [input() for _ in range(m)]

vote_count = {name: 0 for name in names}

for vote in votes:
    if vote in vote_count:
        vote_count[vote] += 1
    else:
        reg = None
        cnt = 0
        for name in names:
            if len(vote) != len(name):
                continue
            if sum(1 for c1, c2 in zip(vote, name) if c1 != c2) == 1:
                reg = name
                cnt += 1
                if cnt == 2:
                    break
        if cnt == 1:
            vote_count[reg] += 1

for name in names:
    print(vote_count[name])
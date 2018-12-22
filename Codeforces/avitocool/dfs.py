n = 7
adj = [[], [2, 6, 3], [5, 1, 3], [1, 4, 2], [3, 5], [2, 4], [7, 1], [6]]
seen = [0]*(n + 1)

def dfs(src):
    print(src)
    seen[src] = 1
    for v in adj[src]:
        if(seen[v] == 0):
            dfs(v)

def main():
    dfs(1)

if __name__ == '__main__':
    main()
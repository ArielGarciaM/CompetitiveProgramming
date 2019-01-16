#include <bits/stdc++.h>
using namespace std;

/* Constantes. Máximo número de vértices e infinito para los flujos que manejamos */
const int MAXN = 5005;
const int INF = 1e9;

/*
 * src y dst son la fuente y el destino.
 * dist es la distancia para BFS
 * ptr indica el vecino más grande de un vértice que hemos visitado en DFS.
 */
int dist[MAXN], ptr[MAXN], src, dst;

/*
 * Estructura chida para aristas del flujo
 * to: vértice al cual va la arista.
 * rev: posición de la arista inversa en la lista de adyacencia de to.
 * f: flujo actual, los residuales se representan con negativos.
 * cap: capacidad de la arista.
 */
struct Edge {
    int to, rev, f, cap;
};

// Lista de adyacencia
vector<Edge> G[MAXN];

/*
 * Agrega una arista de u a v con capacidad v.
 * Esto NO agrega una arista de la misma capacidad de v a u, el flujo de v a u por la gráfica residual
 * lo consideramos negativo. Se pueden agregar aristas múltiples entre dos vértices y aristas de un vértice
 * a si mismo.
 */
void addEdge(int u, int v, int cap) {
    G[u].push_back(Edge({v, (int)G[v].size(), 0, cap}));
    G[v].push_back(Edge({u, (int)G[u].size() - 1, 0, 0}));
}

/*
 * BFS desde src. Si esto no se entiende tenemos un pedo xd. Regresa true si logramos llegar a dst. O(m)
 */
bool bfs() {
    queue<int> q({src});
    memset(dist, -1, sizeof dist);
    dist[src] = 0;
    while(!q.empty() && dist[dst] == -1) {
        int u = q.front();
        q.pop();
        for(auto e : G[u]) {
            int v = e.to;
            // Consideramos solo las aristas por las cuales aún se puede mandar flujo en la residual.
            if(dist[v] == -1 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[dst] != -1;
}

/*
 * Encuentra un blocking flow en la gráfica de niveles, O(mn). Básicamente es un greedy que manda todo lo que puede.
 * u es el vértice desde el cual mandamos flujo.
 * f es el máximo flujo que podemos mandar por el camino que ya recorrimos.
 */
long long dfs(int u, int f) {
    // Llegamos al destino, o el camino no nos permite mandar flujo.
    if(u == dst || !f)
        return f;
    // Aquí ptr[u] nos sirve para no andar viendo muchas veces aristas por las cuales ya mandamos flujo. Sin esto el algoritmo es un pito.
    for(int &i = ptr[u]; i < G[u].size(); i++) {
        Edge &e = G[u][i];
        int v = e.to;
        // Solo mandamos flujo por aristas que vayan hacia adelante. Sin esto regresas a la complejidad O(mf) de Ford-Fulkerson general,
        // pero con una constante mucho más ojete
        if(dist[v] != dist[u] + 1)
            continue;
        // Mandamos todo el flujo posible por la arista (si mandamos más de e.cap - e.f se jode).
        // Notese que este if solo se ejecuta si logramos mandar algo positivo.
        if(int df = dfs(v, min(f, e.cap - e.f))) {
            // Añadimos el flujo normal a la arista.
            e.f += df;
            // Añadimos el flujo residual (negativo) a la arista que va en la dirección opuesta.
            G[v][e.rev].f -= df;
            // Bien hecho equipo, mandamos un chingo de flujo.
            return df;
        }
    }
    // No se mandó ni merga :c
    return 0;
}

/*
 * Hace un dinic xd 
 */
long long dinic() {
    long long mf = 0;
    // Mientras haya caminos de aumento...
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        // ...añadimos todo el flujo posible.
        while(long long pushed = dfs(src, INF))
            mf += pushed;
    }
    // Por el análisis chido de dinic, eliminamos todos los caminos de aumento en O(n) iteraciones, dando O(n^2m) ya que
    // encontrar un blocking flow es O(mn).
    return mf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    src = 1, dst = n;
    while(m--) {
        int u, v, cap;
        cin >> u >> v >> cap;
        addEdge(u, v, cap);
    }
    cout << dinic() << endl;
}
/*  191307094 | Mohammad Nazir Sharifi */
#include <stdio.h>
#include <stdbool.h>

#define INF 9999
#define V 6 

/* fonksiyon prototipleri */

// Minimum mesafe değerine sahip tepe noktasını bulma fonksiyonu
int minDistance(int dist[], bool visited[]); 
// Başlangıç noktasından hedefe en kısa yolu yazdıran fonksiyonu
void printPath(int parent[], int j); 
// Nihai çözümü, yani kaynaktan diğer tüm köşelere olan en kısa mesafeleri yazdırma fonksiyonu
void printSolution(int dist[], int parent[], int src);
void printSolution(int dist[], int parent[], int src);
// Dijkstra'nın algoritmasını uygulayan fonksiyon
void dijkstra(int graph[V][V], int src);


int main()
{
    int graph[V][V] = {
    {0, 4, 2, 0, 0, 0},
    {4, 0, 1, 5, 0, 0},
    {2, 1, 0, 8, 10, 0},
    {0, 5, 8, 0, 2, 6},
    {0, 0, 10, 2, 0, 3},
    {0, 0, 0, 6, 3, 0}};

    int source = 0;

    dijkstra(graph, source);

    return 0;
}


int minDistance(int dist[], bool visited[])
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("%c ", j == 5 ? 'Z' : j + 'A');
}


void printSolution(int dist[], int parent[], int src)
{
    printf("\n191307094 | Mohammad Nazir Sharifi\n");
    printf("---------------------------------------\n");
    printf("DIJKSTRA EN KISA YOL ALGORİTMASI\n");
    printf("---------------------------------------\n\n\n");
    printf("Vertex\t\tMesafe\tKisa Yol");
    for (int i = 0; i < V; i++)
    {
        printf("\n%c -> %c\t\t%d\t\t\t%c ", src + 'A', i == 5 ? 'Z' : i + 'A', dist[i], src + 'A');
        printPath(parent, i);
    }
    printf("\n");
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];      
    bool visited[V]; 
    int parent[V];   

    // Tüm mesafeleri SONSUZ olarak başlat ve ziyaret edilen[]'i yanlış olarak ayarla
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src);
}
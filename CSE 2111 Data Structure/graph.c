#include <stdio.h>
#define N 5

int graph[N][N];

void clear_graph(){
    int a,b;
    for(a=0;a<N;a++){
        for(b=0;b<N;b++){
            graph[a][b] = -5;
        }
    }
}

void fill_graph(){
    graph[0][1]=12;
    graph[0][2]=5;
    graph[0][3]=3;
    graph[1][0]=20;
    graph[1][3]=4;
    graph[2][0]=10;
    graph[2][3]=11;
    graph[3][2]=12;
    graph[3][4]=19;
    graph[4][1]=25;
    graph[4][2]=30;
    graph[4][3]=50;
}

void display(){
    int a,b;
    for(a=0;a<N;a++){
        for(b=0;b<N;b++){
            printf("%d\t",graph[a][b]);
        }
        printf("\n");
    }
}

void max_cost(){
    int a,b;
    int a_node=0,b_node=0;
    int max_cost = -9999;

    for(a=0;a<N;a++){
        for(b=0;b<N;b++){
            if(graph[a][b] != -5 && graph[a][b] > max_cost){
                max_cost = graph[a][b];
                a_node = a;
                b_node = b;
            }
        }
    }
    printf("\nMax cost is %d from node %d to node %d\n",max_cost,a_node,b_node);
}

void min_cost(){
    int a,b;
    int a_node=0,b_node=0;
    int min_cost = 9999;

    for(a=0;a<N;a++){
        for(b=0;b<N;b++){
            if(graph[a][b] != -5 && graph[a][b] < min_cost){
                min_cost = graph[a][b];
                a_node = a;
                b_node = b;
            }
        }
    }
    printf("Min cost is %d from node %d to node %d\n",min_cost,a_node,b_node);
}

int main(){
    clear_graph();
    fill_graph();

    printf("Graph:\n");
    display();

    max_cost();
    min_cost();

    return 0;
}

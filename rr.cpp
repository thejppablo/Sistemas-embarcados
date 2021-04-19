#include<iostream>

using namespace std;
//função para obtermos o waiting time 
void findWaitingTime(int n, int bt[], int wt[], int quantum)
{
int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];

    int t = 0; // variável para o tempo
    int over = 1;

    // percorrer o processo em round robin até que não sobre nenhum.
    while (1)
    {
        bool done = true;

        // percorre todos os processos um por um.
        for (int i = 0 ; i < n; i++)
        {
        	t += over;
            // verifica se  o burst time é menor que 0.
            if (rem_bt[i] > 0)
            {
                done = false; 

                if (rem_bt[i] > quantum)
                {
                    // basicamente diz quanto tempo o processo demorou para ser finalizado.
                    t += quantum;

                    // diminui o burst time do processo atual pelo quantum.
                    rem_bt[i] -= quantum;
                }

                // se o burst time for igual ou menor ao quantum o processo está para ser finalizado.
                else
                {
                    // basicamente diz quanto tempo o processo demorou para ser finalizado.
                    t = t += rem_bt[i];

                    // WaitingTime = tempo_total - burst_time do processo
                    wt[i] = t - bt[i];

                    // quando o processo for finalizado rem_bt = 0.
                    rem_bt[i] = 0;
                }
            }
        }
        //finalizando os processos
        if (done == true)
          break;
    }
}
 
//função para obtermos o turn around
void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{

    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

//fução para obtermos o tempo médio
void findAverageTime(int n, int bt[], int at[], int quantum)
{
	int wt[n], tat[n];
	int total_wt = 0, total_tat = 0;

    findWaitingTime(n, bt, wt, quantum);

    findTurnAroundTime(n, bt, wt, tat);

    cout << "|Processes| "<< " |Burst time| "<< "|Arrival Time|" << " |Waiting time| " << " |Turn around time|\n";

    // calcula o waiting time total e o turn around total.
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i << "\t\t" << bt[i] <<"\t    "<< at[i] <<"\t\t "<< wt[i] <<"\t\t  " << tat[i] <<"\t\t    " << endl;
    }

    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}

int main()
{

 
	int n;
    
    cout<<"Qtd de processos: ";
    cin>>n;
	int burst_time[n]= {};
	int arrival_time[n]= {};
	int quantum;
    for(int i = 0; i < n; i++) {
    	cout<<"Arrival time: ";
        cin>>arrival_time[i];
        cout<<"Burst time: ";
        cin>>burst_time[i];
        
    }
    cout<<"quantum: ";
	cin>>quantum;
    cout<<endl;
    
    findAverageTime(n, burst_time, arrival_time, quantum);
    return 0;

}

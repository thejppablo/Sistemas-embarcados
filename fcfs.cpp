#include<iostream>

using namespace std;

int * arr_dinamico(int qnt){
    int x;
    int *arr = new int(qnt);
    for (int x = 0; x < qnt; x++){
        arr[x] = 0;

    }
    return arr;
} 

void findWaitingTime(int n, int bt[], int at[], int wt[])
{
	 int * tempo_servico = arr_dinamico(n);
	 tempo_servico[0] = 0;

    wt[0] = 0;
 

    for (int i = 1; i < n ; i++)
    {
    	tempo_servico[i] = (tempo_servico[i-1] + bt[i-1]);
        wt[i] =  tempo_servico[i] - at[i];
        if (wt[i] < 0){
        	wt[i] = 0;
		} 

    }
}
 

void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{

    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int n, int wt[], int tat[])
{
	int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
 	cout << "Average Waiting Time : "<< (float)total_wt / (float)n;
    cout << "\nAverage Turn-Around Time: "<< (float)total_tat / (float)n;

}
  

void FCFS(int n, int bt[], int at[])
{
    int wt[n], tat[n];
 
    
    findWaitingTime(n, bt, at, wt);
 
    
    findTurnAroundTime(n, bt, wt, tat);
 	

    cout << "Processes  "<< " Burst time  "<< " Arrival time  "<< " Waiting time  " << " Turn-Around Time  "<< " Complete Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i << "\t\t" << bt[i] <<"\t    "<< at[i] <<"\t\t "<< wt[i] <<"\t\t  " << tat[i] <<"\t\t    " << tat[i] + at[i] <<endl;
    } 
    findAverageTime(n,wt, tat);



}



int main()
{

 
	int n;
    
    cout<<"Qnt de Processos: ";
    cin>>n;
	int burst_time[n]= {};
	int arrival_time[n]= {};
    for(int i = 0; i < n; i++) {
    	cout<<"Arrival time: ";
        cin>>arrival_time[i];
        cout<<"Burst time: ";
        cin>>burst_time[i];
        cout<<endl;
    }

    
    FCFS(n,  burst_time, arrival_time);
    return 0;

}

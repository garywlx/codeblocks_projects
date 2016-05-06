#include <iostream>

using namespace std;

int main()
{
    int d,sumTime,minTime=0,maxTime=0;
    int i;
    while(cin >> d >>sumTime){
        int time[d][2];
        for(i=0;i<d;i++){
            cin >> time[i][0] >> time[i][1];
            minTime+=time[i][0];
            maxTime+=time[i][1];
        }
        if(maxTime<sumTime){
            cout << "No" << endl;
        }
        else{
            //i=0;
            cout << "Yes" << endl;
            int myTime=sumTime-minTime;
            for(i=0;i<d;i++){
                int diffTime=time[i][1]-time[i][0];
                if(diffTime<myTime){
                    cout << diffTime + time[i][0] << " ";
                    myTime-=diffTime;
                }else{
                    cout << time[i][0] << " ";
                }

            }
            cout << endl;
        }
    }
    return 0;
}

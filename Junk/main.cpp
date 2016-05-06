#include <iostream>
#include <queue>
using namespace std;
typedef struct
{
    int n[4];
    int step = 0;
} State;
int full[] = {11,7,6,5};
//static State state2 = new State();
int vis[10][8][5][3];


bool bfs(State state2, int start, int end)
{
    //自己不能倒酒给自己
    if(start == end) return false;
    //start杯子为空不能倒酒
    if(state2.n[start] == 0) return false;
    //end杯子满了不能倒酒
    if(state2.n[end] == full[end]) return false;

    //将A中的酒倒入B中
    if(state2.n[end] + state2.n[start] <= full[end])
    {
        state2.n[end] += state2.n[start];
        state2.n[start] = 0;
    }
    //A中的酒没有完全倒干净
    else
    {
        state2.n[start] = state2.n[start] - (full[end] - state2.n[end]);
        state2.n[end] = full[end];
    }
    if(vis[state2.n[0]][state2.n[1]][state2.n[2]][state2.n[3]] == 1) return false;
    else
        vis[state2.n[0]][state2.n[1]][state2.n[2]][state2.n[3]] = 1;

    state2.step++;
    return true;

}
bool isFinished(State state, int end[])
{
    int flag = 1;
    for(int i = 0; i < 4; i++)
    {
        if(state.n[i] != end[i])
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1) return true;
    else return false;
}
void setVol(State &state,int N[])
{
    for(int i = 0; i < 4; i++)
        state.n[i] = N[i];
}
int main()
{
    //cout << "Hello world!" << endl;
    int target[4];
    queue<State> q;
    //int bottle1,bottle2,bottle3,bottle;
    cin >> target[0] >> target[1] >> target[2] >> target[3];
    if(target[0]+target[1]+target[2]+target[3]!=10)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < 4; i++)
        if(target[i] > full[i])
        {
            cout << -1 << endl;
            return 0;
        }
    State state;
    int start[] = {10,0,0,0};
    setVol(state,start);
    state.step=0;
    q.push(state);
    int flag = 0;
    while(!q.empty())
    {
        State tmp=q.front();
        q.pop();
        if(isFinished(tmp, target))
        {
            flag  = 1;
            cout << tmp.step << endl;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                State state2;
                setVol(state2,tmp.n);
                state2.step=tmp.step;
                if(bfs(state2,i, j))
                {
                    q.push(state2);
                }
            }//for j
        }//fo
    }
    if(flag == 0)
        cout << -1 << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 1;
struct IP
{
    int time;
    int state;      // 1:未分配 2:待分配 3:占用 4:过期
    string name;
} ip[N];

int main()
{
    int n, tdef, tmax, tmin;
    string host;
    cin >> n >> tdef >> tmax >> tmin >> host;

    for (int i = 1; i <= n; i++) ip[i].state = 1;

    int n2;
    scanf("%d", &n2);
    for (int k = 1; k <= n2; k++) {
        string shost, rhost, type;
        int seq, ip2, time;
        cin >> seq >> shost >> rhost >> type >> ip2 >> time;

        for (int i = 1; i <= n; i++) {
            if (ip[i].state == 2 && ip[i].time <= seq) {
                ip[i].state = 1;
                ip[i].name = "";
                ip[i].time = 0;
            } else if (ip[i].state == 3 && ip[i].time <= seq) {
                ip[i].state = 4;
                ip[i].time = 0;
            }
        }

        if (rhost == host || rhost == "*" || type == "REQ") {
            if (type != "DIS" && type != "REQ") continue;
            if ((rhost == "*" && type != "DIS") || (rhost == host && type=="DIS")) continue;
            if (type == "DIS") {
                int select = -1;
                for (int i = 1; i <= n; i++)
                    if (ip[i].state != 1 && ip[i].name == shost) {
                        select = i;
                        break;
                    }
                if (select == -1) {
                    for (int i = 1; i <= n; i++)
                        if (ip[i].state == 1) {
                            select = i;
                            break;
                        }
                }
                if (select == -1) {
                    for (int i = 1; i <= n; i++)
                        if (ip[i].state == 4) {
                            select = i;
                            break;
                        }
                }
                if (select != -1) {
                    ip[select].state = 2;
                    ip[select].name = shost;

                    if (time == 0) ip[select].time = seq + tdef;
                    else if (tmin <= time - seq && time - seq <= tmax) ip[select].time = time;
                    else if (time - seq < tmin) ip[select].time = seq + tmin;
                    else if (time - seq > tmax) ip[select].time = seq + tmax;
                    cout << host << " " << shost << " OFR " << select << " " << ip[select].time<<endl;
                }
            } else if (type == "REQ") {
                if (rhost != host) {
                    for (int i = 1; i <= n; i++)
                        if (ip[i].name == shost && ip[i].state == 2) {
                            ip[i].state = 1;
                            ip[i].name = "";
                            ip[i].time = 0;
                        }
                } else {
                    if (1 <= ip2 && ip2 <= n && ip[ip2].name == shost) {
                        ip[ip2].state = 3;
                        if (time == 0) ip[ip2].time = seq + tdef;
                        else if (tmin <= time - seq && time - seq <= tmax) ip[ip2].time = time;
                        else if (time- seq < tmin) ip[ip2].time = seq + tmin;
                        else if (time - seq > tmax) ip[ip2].time = seq + tmax;
                        cout << host << " " << shost << " ACK " << ip2 << " " << ip[ip2].time << endl;
                    } else
                        cout << host << " " << shost << " NAK " << ip2 << " 0" << endl;
                }
            }
        }
    }

    return 0;
}
#include<iostream>
using namespace std;
struct jgt
{
	int id = 0;
	int live = 1;
	jgt* next = nullptr;
};
int main() {
	int p = 41;
	int c = 3;
	//cin >> p;
	//cin >> c;
	jgt* tou = new jgt;
	jgt* wei = new jgt;
	tou->id = 1;
	tou->next = wei;
	wei->id = 2;
	for (int i = 3; i <= p; i++) {
		jgt* xin = new jgt;
		xin->id = i;
		wei->next = xin;
		wei = xin;
	}
	wei->next = tou;
	/*jgt* xin1 = new jgt;
	xin1 = tou;
	for (int i = 1; i <= p + 1; i++) {
		cout << xin1->id << endl;
		xin1 = xin1->next;
	}
	delete xin1;*/
	jgt* newpoint = new jgt;
	newpoint = tou;
	int i = 1;
	int j = 0;
	int the_middle = (p / 2) * c;
	int the_end = p * c;
	while (i <= the_end)
	{
		if (newpoint->live == 1) {
			if (j == 1) {
				i++;
				if (i % 3 == 0) {
					cout << newpoint->id << "--" << i << "--" << i / 3 << endl;//输出死亡id
					newpoint->live = 0;
					newpoint = newpoint->next;
					if (newpoint->live == 1) {
						i++;
					}
				}
				j = 0;
				newpoint = newpoint->next;
				if (newpoint->live == 1) {
					i++;
					if (i % 3 == 0) {
						cout << newpoint->id << "--" << i << "--" << i / 3 << endl;//输出死亡id
						newpoint->live = 0;
						newpoint = newpoint->next;
						if (newpoint->live == 1) {
							i++;
						}
					}
				}
			}
			else {
				if (newpoint->next->live == 1) {
					i++;
				}
				newpoint = newpoint->next;
				if (i % 3 == 0) {
					cout << newpoint->id << "--" << i << "--" << i / 3 << endl;//输出死亡id
					newpoint->live = 0;
					if (newpoint->next->live == 1) {
						i++;
					}
					newpoint = newpoint->next;
				}
			}
		}
		else {
			newpoint = newpoint->next;
			j = 1;
		}
	}
	return 0;
}
/*
3--3--1
6--6--2
9--9--3
12--12--4
15--15--5
18--18--6
21--21--7
24--24--8
27--27--9
30--30--10
33--33--11
36--36--12
39--39--13
1--42--14
5--45--15
10--48--16
14--51--17
19--54--18
23--57--19
28--60--20
32--63--21
37--66--22
41--69--23
7--72--24
13--75--25
20--78--26
26--81--27
34--84--28
40--87--29
8--90--30
17--93--31
29--96--32
38--99--33
11--102--34
25--105--35
2--108--36
22--111--37
4--114--38
35--117--39
16--120--40
31--123--41
*/
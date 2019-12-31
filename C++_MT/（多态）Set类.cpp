#include "CSet.h"
bool Set::operator <=(const Set &s) const
{
	if (!n){
		return true;
	}
	if (n> s.n){
		return false;
	}

	for (int i= 1; i<= n; ++i){
		if (!s.IsElement(pS[i])){
			return false;
		}
	}
	return true;
}
bool Set::operator ==(const Set &s) const
{
	if (n!= s.n){
		return false;
	}

	for (int i= 1; i<= n; ++i){
		if (!IsElement(s.pS[i])){
			return false;
		}
	}
	return true;
}
Set & Set::operator +=(int e)
{
	if (!IsElement(e)){
		++n;
		int *store= new int [n+1];
		for (int i= 1; i< n; ++i){
			store[i]= pS[i];
		}
		store[n]= e;
		int *temp= pS;
		pS= store;
		delete []temp;
	}

	return *this;
}
Set & Set::operator -=(int e)
{
	if (IsElement(e)){
		int rubish;
		for (rubish= 1; rubish<= n; ++rubish){
			if (pS[rubish]==e){
				break;
			}
		}
		int *store= new int [n];
		for (int i= 1; i< rubish; ++i){
			store[i]= pS[i];
		}
		for (int i= rubish+1; i<= n; ++i){
			store[i-1]= pS[i];
		}
		--n;
		int *temp= pS;
		pS= store;
		delete []temp;
	}
	return *this;
}
Set Set::operator | (const Set &s) const
{
	Set ans;
	ans.n= n;
	if (0!= n){
		ans.pS= new int[(ans.n)+1];
		for (int i= 1; i<= ans.n; ++i){
			ans.pS[i]= pS[i];
		}
	}
	for (int i= 1; i<= s.n; ++i){
		if (!IsElement(s.pS[i])){
			ans+= s.pS[i];
		}
	}
	return ans;
}
Set Set::operator & (const Set &s) const
{
	Set ans;
	ans.n= n;
	if (0!=n){
		ans.pS= new int[(ans.n)+1];
		for (int i= 1; i<= ans.n; ++i){
			ans.pS[i]= pS[i];
		}
	}
	for (int i= 1; i<= s.n; ++i){
		if (!IsElement(s.pS[i])){
			ans-= s.pS[i];
		}
		if (!s.IsElement(pS[i])){
			ans-= pS[i];
		}
	}

	return ans;
}
Set Set::operator - (const Set &s) const
{
	Set ans;
	ans.n= n;
	if (0!=n){
		ans.pS= new int[(ans.n)+1];
		for (int i= 1; i<= ans.n; ++i){
			ans.pS[i]= pS[i];
		}
	}
	for (int i= 1; i<= s.n; ++i){
		if (IsElement(s.pS[i])){
			ans-= s.pS[i];
		}
	}

	return ans;
}
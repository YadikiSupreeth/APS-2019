
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
#include <bits/stdc++.h>
#define sz size()
#define pb push_back
#define rep(i, n) for (long long int i = 0; i < n; i++)
#define fd(i, a, b) for (long long int i = a; i >= b; i--)

#define N 111111

struct node
{
	long long int count;
	node *left, *right;

	node(int count, node *left, node *right) : count(count), left(left), right(right) {}

	node *insert(long long int l, long long int r, long long int w);
};

node *null = new node(0, NULL, NULL); //see line 135

node *node::insert(long long int l, long long int r, long long int w)
{
	if (l <= w && w < r)
	{
		// With in the range, we need a new node
		if (l + 1 == r)
		{
			return new node(this->count + 1, null, null);
		}

		long long int m = (l + r) >> 1;

		return new node(this->count + 1, this->left->insert(l, m, w), this->right->insert(m, r, w));
	}

	// Out of range, we can use previous tree node.
	return this;
}

long long int query(node *a, node *b, long long int l, long long int r, long long int k)
{
	if (l + 1 == r)
	{
		return l;
	}

	long long int m = (l + r) >> 1;
	long long int count = a->left->count - b->left->count;
	if (count >= k)
		return query(a->left, b->left, l, m, k);

	return query(a->right, b->right, m, r, k - count);
}

long long int a[N], RM[N];
node *root[N];
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	long long int n, k, t, m;
	scanf("%lld", &t);
	while (t--)
	{
		cin >> n >> k;
		//scanf("%lld %lld", &n, &k);

		map<long long int, long long int> M;
		rep(i, n)
		{
			//scanf("%lld", &a[i]);
			cin >> a[i];
			M[a[i]];
		}

		long long int maxi = 0;

		for (map<long long int, long long int>::iterator it = M.begin(); it != M.end(); it++)
		{
			M[it->first] = maxi;
			RM[maxi] = it->first;
			maxi++;
		}

		null->left = null->right = null;
		rep(i, n)
		{
			// Build a tree for each prefix using segment tree of previous prefix
			root[i] = (i == 0 ? null : root[i - 1])->insert(0, maxi, M[a[i]]);
		}
		long long int sup = 0;

		for (long long int i = 0; i < n; i++)
		{
			unordered_map<long long int, long long int> upmap;
			//printf("\n");
			for (long long int j = i; j < n; j++)
			{

				long long int aa = (j - i + 1);
				if (k % aa == 0)
					m = (long long int)(k / aa);
				else
					m = ((long long int)(k / aa)) + 1;
				upmap[a[j]] += 1;
				long long int index = 0;
				if (k % m == 0)
					index = (long long int)(k / m);
				else
					index = ((long long int)(k / m)) + 1;
				long long int ans = query(root[j], (i == 0 ? null : root[i - 1]), 0, maxi, index);

				//long long int kount = count(a + i, a + j + 1, RM[ans]);
				long long int kount=upmap[RM[ans]];

				if (upmap[kount] > 0)
					sup++;
			}
		}
		cout<<sup<<"\n";
		//printf("%lld\n", sup);
	}
}
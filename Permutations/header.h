#include<vector>

using namespace std;

//function which input permutation vector
void writePermutation(int n, vector<int> &v) {
	for (int i = 1; i <= n; ++i) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		v.push_back(a);
	}
}
//function which output permutation vector
void readPermutation(int n, vector<int> &v) {
	for (int i = 1; i <= n; ++i) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}
//function which reverse permutation vector
vector<int> reverseFunc(vector<int> a) {
	vector<int> b;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			if (a[j]-1 == i) {
				b.push_back(j+1);
			}
		}
	}

	return b;
}
//function which compound permutation vectors
vector<int> permutationCompound(vector<int> a, vector<int> b) {
	vector<int> c;

	int n = a.size();

	for (int i = 0; i < n; ++i) {
		int d, e;
		e = b[i];
		d = a[e-1];
		c.push_back(d);
	}

	return c;
}

void checkSign(vector<int> a) {
	int x = 0;
	vector<vector<int>> d;
	for (int i = 0; i < a.size()-1; ++i) {
		for (int j = i + 1; j < a.size(); ++j) {
			vector<int> f;
			if (a[i] > a[j]) {
				++x;
				f.push_back(a[i]);
				f.push_back(a[j]);
				d.push_back(f);
			}
		}
	}
	cout << "Amount of inversions: " << x << endl;
	cout << "Inversions: " << endl;
	for (int i = 0; i < d.size(); ++i) {
		cout << "(" << d[i][0] << "," << d[i][1] << ") ";
	}
	cout << endl;
	cout << "The sign of permutation: ";
	if (x % 2 == 1) {
		cout << -1 << endl;
	}
	else {
		cout << 1 << endl;
	}
}

//compound function
void compound() {
	vector<int> f, g;
	int n;
	cout << "Write size of permutation: ";
	cin >> n;
	cout << endl;
	cout << "Write permutation f:" << endl;
	writePermutation(n, f);
	cout << "Write permutation g:" << endl;
	writePermutation(n, g);
	vector<int> fg = permutationCompound(f, g);
	vector<int> gf = permutationCompound(g, f);
	cout << endl;
	cout << "Permutation compound f o g: " << endl;
	readPermutation(n, fg);
	cout << "\nPermutation compound f o g: " << endl;
	readPermutation(n, gf);
	cout << endl;
}
//reverse solo permutation
void reverseSolo() {
	vector<int> f;
	int n;
	cout << "Write size of permutation: ";
	cin >> n;
	cout << endl;
	cout << "Write permutation f:" << endl;
	writePermutation(n, f);
	vector<int> rf = reverseFunc(f);
	cout << endl;
	cout << "Reverse permutation f^(-1): " << endl;
	readPermutation(n, rf);
	cout << endl;
}

void reversePerm() {
	vector<int> f, g;
	int n;
	cout << "Write size of permutation: ";
	cin >> n;
	cout << endl;
	cout << "Write permutation f:" << endl;
	writePermutation(n, f);
	cout << "Write permutation g:" << endl;
	writePermutation(n, g);
	vector<int> fg = permutationCompound(f, g), gf = permutationCompound(g, f);
	vector<int> rfg = reverseFunc(fg), rgf = reverseFunc(gf);
	cout << endl;
	cout << "Reverse permutation (f o g)^(-1): " << endl;
	readPermutation(n, rfg);
	cout << endl;
	cout << "Reverse permutation (g o f)^(-1): " << endl;
	readPermutation(n, rgf);
	cout << endl;
}

void sign() {
	vector<int> f;
	int n;
	cout << "Write size of permutation: ";
	cin >> n;
	cout << endl;
	cout << "Write permutation f:" << endl;
	writePermutation(n, f);
	checkSign(f);
}

//program interface
void interFace() {
	bool eve = true;
	while (eve) {
		int choice;
		cout << "Hi! Welcome to my permutations program!" << endl;
		cout << "What type of operation do you need?" << endl;
		cout << "1. Permutations compound" << endl;
		cout << "2. Reverse permutation" << endl;
		cout << "3. Reverse permutations compound" << endl;
		cout << "4. Sign of permutation" << endl;
		cout << "5. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			compound();
			break;
		case 2:
			reverseSolo();
			break;
		case 3:
			reversePerm();
			break;
		case 4:
			sign();
			break;
		case 5:
			eve = false;
			break;
		}
	}
}

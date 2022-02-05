void Toh(int n, char A, char B, char C) {
	if(n == 0) return;
	Toh(n - 1, A, C, B);
	cout << A << " to " << C << "\n";
	Toh(n - 1, B, A, C);
}
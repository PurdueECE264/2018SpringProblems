
int main() {
	StudentDatabase * db = Connect("database.txt");
	int nval = CompareByName(db -> students, db -> students + 1);
	int aval = CompareByAge(db -> students, db -> students + 1);
	printf("%d\n", nval < 0);
	printf("%d\n", aval > 0);
	Close(db);
	return 0;
}

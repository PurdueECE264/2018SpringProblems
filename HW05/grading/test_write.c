
int main(int argc, char **argv) {
	StudentDatabase * db = Connect("database.txt");
	int write_success = WriteDatabase("write_success.txt", db);
	printf("%d\n", write_success);
	int write_fail = WriteDatabase("write_fail.txt", db);
	printf("%d\n", write_fail);
	Close(db);
    return 0;
}


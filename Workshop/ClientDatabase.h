#include"Client.h"


class ClientDatabase {
private:
	vector<Client> clientBase;
	vector<Client>::iterator it;
	string statFilename = "clientdb.txt";
	ClientDatabase();
	~ClientDatabase();
public:
	ClientDatabase(ClientDatabase& other) = delete;
	/**
	 * Singletons should not be assignable.
	 */
	void operator=(const ClientDatabase&) = delete;

	static ClientDatabase& getInstance() {
		static ClientDatabase instance;  // Inicjalizacja instancji przy pierwszym wywo³aniu
		return instance;
	}
	Client getClientThroughNumber(string);

	void updateCollection();

	void addClientToBase(ClientData&);

	vector<Client> fetchClientCollection();

	void print();


};

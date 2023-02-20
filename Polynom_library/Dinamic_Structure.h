class Dinamic_Structure
{
public:
	Dinamic_Structure();
	void push_back(int &elem);
	void push_front(int &elem);
	void delete_elem(unsigned int index);
	int get_size();
	int get_elem(int index);
	const int* get_c_arr();
	int get_max();
	int get_min();
	void sort_struct();
	~Dinamic_Structure();

private:
	int* arr = nullptr;
	unsigned int counter = 0;
	unsigned int size = 0;
};

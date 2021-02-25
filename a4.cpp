#include<iostream>
using namespace std;
 
class Matrix{
private:
	int row;
	int col;
	int size;
	double* data;
 
public:
	Matrix(int r,int c){
		row = r;
		col = c;
		size = row * col;
		data = new double[size];
		cout<<"请输入"<<row<<"*"<<col<<"矩阵："<<endl;
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				cin >> data[i*row+j];
			}
		}
	}
 
	~Matrix(void){
		delete []data;
	}
	Matrix (const Matrix& M)
	{
		col = M.col;
		row = M.row;
		size = M.size;
		data = new double [M.size];
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				data[i*row+j] = M.data[i*row+j];
			}
		}
 
	}
	Matrix& operator=(Matrix& M)
	{
		if (this == &M)
		{
			return *this;
		}
		col = M.col;
		row = M.row;
		size = M.size;
		data = new double [M.size];
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				data[i*row+j] = M.data[i*row+j];
			}
		}
		return *this;
	}
	Matrix operator+(Matrix& M){
		Matrix M1 = *this;
		if(col == M.col && row == M.row){
			for(int i=0; i<M1.row; i++){
				for(int j=0; j<M1.col; j++){
					M1.data[i*row+j] = data[i*row+j] + M.data[i*row+j];
				}
			}
			return M1;
		}
		else{
			cout << "矩阵行或列数不相等，不能相加" << endl;
			return M1;
		}
	}
	Matrix operator-(Matrix& M){
		Matrix M1 = *this;
		if(col == M.col && row == M.row){
			for(int i=0; i<M1.row; i++){
				for(int j=0; j<M1.col; j++){
					M1.data[i*row+j] = data[i*row+j] - M.data[i*row+j];
				}
			}
			return M1;
		}
		else{
			cout << "矩阵行或列数不相等，不能相减" << endl;
			return M1;
		}
	}
	friend ostream& operator<<(ostream& out,Matrix& M){
		for(int i=0; i<M.row; i++){
			for(int j=0; j<M.col; j++){
				out << M.data[i*M.row+j] << ' ';
			}
			out << endl;
		}
		return out;
	}
};

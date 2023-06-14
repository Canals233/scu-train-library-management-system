#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Book
{
public:
    string bookName;      //书名,用于查找
    string author;        //作者名,用于查找
    string publishDate;   //出版日期,用于查找
    string ISBN;          // ISBN 号,用于查找
    string hasEbook;      //电子书
    string hasPaperBook;  //纸质书
    string publisher;     //出版商,用于查找
    string profile;       //该书内容简介
    string is_lend = "0"; //判断书是否借出
};

class BookSource
{
public:
    vector<Book> books;

    BookSource()
    {
        file2Source();
        //初始化时读取文件
    }

    void file2Source()
    {
        
        fstream file;
        file.open("source.csv", ios::in);//只读打开
        if (!file)
        {
            cout << "载入数据时 source.csv 打开失败了" << endl;
            return;
        }
        Book skip;
            getline(file, skip.bookName, ',');
            getline(file, skip.author, ',');
            getline(file, skip.publishDate, ',');
            getline(file, skip.ISBN, ',');
            getline(file, skip.hasEbook, ',');
            getline(file, skip.hasPaperBook, ',');
            getline(file, skip.publisher, ',');
            getline(file, skip.profile, ',');
            getline(file, skip.is_lend, ',');
            // 跳过首行的列名
        while (1)
        {
            Book newBook;
            getline(file, newBook.bookName, ',');
            getline(file, newBook.author, ',');
            getline(file, newBook.publishDate, ',');
            getline(file, newBook.ISBN, ',');
            getline(file, newBook.hasEbook, ',');
            getline(file, newBook.hasPaperBook, ',');
            getline(file, newBook.publisher, ',');
            getline(file, newBook.profile, ',');
            getline(file, newBook.is_lend, ',');
            printBookDetail(newBook);
            this->books.emplace_back(newBook);
            if (file.eof())
            {
                file.close();
                return;
            }
        }
        // 以上为读取
    }

    void addNewBook()
    {
        Book newBook;
        cout << "请输入新书的以下信息:" << endl;
        cout << "书名:" << endl;
        cin >> newBook.bookName;
        cout << "作者名:" << endl;
        cin >> newBook.author;
        cout << "出版日期:" << endl;
        cin >> newBook.publishDate;
        cout << "ISBN 号:" << endl;
        cin >> newBook.ISBN;
        cout << "有无电子书(0 为无,1 为有):" << endl;
        cin >> newBook.hasEbook;
        cout << "有无纸质书(0 为无,1 为有):" << endl;
        cin >> newBook.hasPaperBook;
        cout << "出版商:" << endl;
        cin >> newBook.publisher;
        cout << "内容简介:" << endl;
        cin >> newBook.profile;
        printBookDetail(newBook);
        this->books.emplace_back(newBook);
    }

    void printBookDetail(Book book)
    {
        cout << "书名:"
             << " " << book.bookName << endl;

        cout << "作者名:"
             << " " << book.author << endl;

        cout << "出版日期:"
             << " " << book.publishDate << endl;

        cout << "ISBN 号:"
             << " " << book.ISBN << endl;

        cout << "有无电子书(0 为无,1 为有):"
             << " " << book.hasEbook << endl;

        cout << "有无纸质书(0 为无,1 为有):"
             << " " << book.hasPaperBook << endl;

        cout << "出版商:"
             << " " << book.publisher << endl;

        cout << "内容简介:"
             << " " << book.profile << endl;

        cout << "是否已经借出 (0 为否,1 为是)" << book.is_lend << endl;
    }
};

int main()
{
    BookSource nowSource;
    // nowSource.addNewBook();
    return 0;
}
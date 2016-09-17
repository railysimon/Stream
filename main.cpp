#include <iostream>

using namespace std;

template <class ClassType>
class Stream
{
private:
        ClassType a,b,c;
public:
        Stream(ClassType data_a, ClassType data_b, ClassType data_c) : a(data_a), b(data_b), c(data_c) {}
        template <typename FriendType>
        friend ostream &operator <<(ostream &stream, Stream<FriendType> object);
        friend ostream &setup(ostream &stream);
        template <typename FriendType>
        friend istream &operator >>(istream &stream, Stream<FriendType> &object);
};

template <typename FriendType>
ostream &operator <<(ostream &stream, Stream<FriendType> object)
{
    stream << object.a << ",";
    stream << object.b << ",";
    stream << object.c << endl;
    return stream;
}

ostream &setup(ostream &stream)
{
    stream.width(5);
    stream.precision(3);
    stream.setf(ios::right);
    return stream;
}

template <typename FriendType>
istream &operator >>(istream &stream, Stream<FriendType> &object)
{
    cout << "Input data: " << endl;
    stream >> object.a >> object.b >> object.c;
    return stream;
}

int main()
{
    Stream<int> object(1,2,3);
    cout << setup << object << endl;
    cin >> object;
    cout << setup << object;

  return 0;
}

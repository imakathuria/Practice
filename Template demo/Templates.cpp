template <typename T,typename U,typename W>
class triplet{
private:
  T x;
  U y;
  W z;
public:
  void getx(T a){
    x=a;
  }
  void gety(U b){
    y=b;
  }
  void getz(W c){
    z=c;
  }
  T valueofx(){
    return x;
  }
  U valueofy(){
    return y;
  }
  W valueofz(){
    return z;
  }
};

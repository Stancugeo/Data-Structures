#include <iostream>
using namespace std;
class String{
private:
    int length ;
    char* Sir ;
public:
    String()
    {
        this->Sir = nullptr ;
        this->length = 0 ;
    }
    String(const char* str)
    {
        if( str != nullptr )
        {
            delete Sir ;
            this->Sir = new char[ strlen(str) + 1 ];
            this->length = strlen(str);
            strcpy(this->Sir,str);
        } else
        {
            this->Sir = nullptr ;
            this->length = 0 ;
        }

    }
    friend ostream& operator<< (ostream & os , const String& Obj  )
    {
        if(Obj.Sir != nullptr)
        {
            for(int i = 0 ; i < Obj.length ; i++ )
            {
                os << Obj.Sir[i] ;
            }
        }


    }
    friend istream& operator>> (istream & is ,  String& Obj )
    {
        string NewString ;
        is >> NewString ;

        Obj.Sir = new char [ NewString.size() + 1 ];
        Obj.length = NewString.size() ;
        for(int i = 0 ; i < NewString.size() ; i++ )
        {
            Obj.Sir[i] = NewString[i] ;
        }


    }
    String & operator= (const String & Obj )
    {
        if(Obj.Sir!=nullptr)
        {
            delete Sir ;
            this->Sir = new char [Obj.length + 1] ;
            strcpy(this->Sir,Obj.Sir);
            this->length = Obj.length ;
        }
        return *this;

    }
    String & operator= (const char ch)
    {
        if(ch != '\0' )
        {
            delete Sir ;
            this->Sir = new char [2] ;
            Sir[0] = ch ;
            Sir[1] = '\0' ;
            this->length = 1 ;
        }
        return *this;
    }
    friend bool operator==(const String & Obj , const String & Obj2 )
    {
        if(Obj.Sir!=nullptr && Obj.Sir!=nullptr)
        {
            if(strcmp(Obj.Sir,Obj2.Sir)==0)
            {
                return true;
            } else return false;
        } else return false;


    }
    friend bool operator==(const String & Obj , const char ch )
    {
        if(Obj.Sir!=nullptr && ch!='\0' )
        {
            if(Obj.length == 1)
            {
                return (Obj.Sir[0] == ch);
            } else return false;
        } else return false;


    }
    friend bool operator==(const char ch , const String & Obj )
    {
        if(Obj.Sir!=nullptr && ch!='\0' )
        {
            if(Obj.length == 1)
            {
                return (Obj.Sir[0] == ch);
            } else return false;
        } else return false;


    }
    friend bool operator!=(const String & Obj , const String & Obj2)
    {
       
        if(Obj.Sir!=nullptr && Obj.Sir!=nullptr)
        {
            if(strcmp(Obj.Sir,Obj2.Sir)!=0)
            {
                return true;
            } else return false;
        } else  return false;
    }
    friend bool operator!=(const String & Obj , const char ch )
    {
        
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length > 1)
            {
                return true;
            } else  return(Obj.Sir[0] != ch);
        } else return false; 
    }
    friend bool operator!=(const char ch , const String & Obj )
    {
        
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length > 1)
            {
                return true;
            } else  return(Obj.Sir[0] != ch);
        } else return false; 
    }
    friend bool operator<(const String & Obj , const String & Obj2)
    {
        if(Obj.Sir!=nullptr && Obj.Sir!=nullptr)
        {
            if(strcmp(Obj.Sir,Obj2.Sir)<0)
            {
                return true;
            } else return false;
        } else return false;
    }
    friend bool operator<(const String & Obj ,const char ch)
    {
       
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length == 1)
            {
                return( Obj.Sir[0] < ch ) ;
            } else return false;
        } else return false; 
    }
    friend bool operator<(const char ch ,const String & Obj)
    {
        
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length == 1)
            {
                return( Obj.Sir[0] < ch ) ;
            } else return false;
        } else return false; 
    }
    friend bool operator>(const String & Obj , const String & Obj2)
    {
        if(Obj.Sir!=nullptr && Obj.Sir!=nullptr)
        {
            if(strcmp(Obj.Sir,Obj2.Sir)>0)
            {
                return true;
            } else return false;
        } else  return false;
    }
    friend bool operator>(const String & Obj , const char ch )
    {
       
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length == 1)
            {
                return( Obj.Sir[0] > ch ) ;
            } else return true ;
        } else return false; 
    }
    friend bool operator>(const char ch  , const String & Obj )
    {
        
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length == 1)
            {
                return( Obj.Sir[0] > ch ) ;
            } else return true ;
        } else return false; 
    }
    friend bool operator>=(const String & Obj , const String & Obj2)
    {
        if(Obj.Sir!=nullptr && Obj.Sir!=nullptr)
        {
            if(strcmp(Obj.Sir,Obj2.Sir)>=0)
            {
                return true;
            } else return false;
        } else return false;
    }
    friend bool operator>=(const String & Obj ,const char ch )
    {
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length == 1)
            {
                return( Obj.Sir[0] >= ch ) ;
            } else return true ;
        } else return false; // siruri nule nu ne pasa
    }
    friend bool operator>=(const char ch ,const String & Obj )
    {
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length == 1)
            {
                return( Obj.Sir[0] >= ch ) ;
            } else return true ;
        } else return false; // siruri nule nu ne pasa
    }
    friend bool operator<=(const String & Obj , const String & Obj2)
    {
        if(Obj.Sir!=nullptr && Obj.Sir!=nullptr)
        {
            if(strcmp(Obj.Sir,Obj2.Sir)<=0)
            {
                return true;
            } else return false;
        } else return false;
    }
    friend bool operator<=(const String & Obj , const char ch)
    {
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length == 1)
            {
                return( Obj.Sir[0] <= ch ) ;
            } else return true ;
        } else return false; // siruri nule nu ne pasa
    }
    friend bool operator<=(const char ch , const String & Obj)
    {
        if(Obj.Sir!=nullptr && ch!='\0')
        {
            if(Obj.length == 1)
            {
                return( Obj.Sir[0] <= ch ) ;
            } else return true ;
        } else return false; // siruri nule nu ne pasa
    }
    friend String  operator+(const String &  Obj , const String & Obj2 )
    {
        String NewString ;
        if(Obj.Sir!=nullptr && Obj2.Sir!=nullptr)
        {
            NewString.Sir = new char [ Obj.length + Obj2.length + 1 ] ;
            NewString.length = Obj.length + Obj2.length  ;
            strcpy(NewString.Sir,Obj.Sir);
            strcat(NewString.Sir,Obj2.Sir);

        } else if(Obj.Sir!=nullptr)
        {

            NewString.Sir = new char [Obj.length + 1 ] ;
            strcpy(NewString.Sir,Obj.Sir);
            NewString.length = Obj.length ;

        } else if(Obj2.Sir!=nullptr)
        {

            NewString.Sir = new char [Obj2.length + 1 ] ;
            strcpy(NewString.Sir,Obj2.Sir);
            NewString.length = Obj2.length ;

        }
        return NewString ;



    }
    friend String  operator+(const char  ch , const String & Obj2 )
    {
        String NewString ;
        if( ch!='\0' && Obj2.Sir!=nullptr)
        {
            NewString.Sir = new char [ Obj2.length + 2 ] ;
            NewString.length = 1 + Obj2.length  ;
            strcpy(NewString.Sir+1,Obj2.Sir);
            NewString.Sir[0] = ch ;
        } else if( ch!='\0' )
        {
            NewString.Sir = new char [2] ;
            NewString.Sir[0] = ch ;
            NewString.Sir[1] = '\0' ;
            NewString.length = 1 ;

        } else if(Obj2.Sir!=nullptr)
        {

            NewString.Sir = new char [Obj2.length + 1 ] ;
            strcpy(NewString.Sir,Obj2.Sir);
            NewString.length = Obj2.length ;

        }
        return NewString ;



    }
    friend String  operator+(const String & Obj2  , const char  ch )
    {
        String NewString ;
        if( ch!='\0' && Obj2.Sir!=nullptr)
        {
            NewString.Sir = new char [ Obj2.length + 2 ] ;
            NewString.length = 1 + Obj2.length  ;
            strcpy(NewString.Sir,Obj2.Sir);
            NewString[strlen(Obj2.Sir)] = ch ;


        } else if( ch!='\0' )
        {
            NewString.Sir = new char [2] ;
            NewString.Sir[0] = ch ;
            NewString.Sir[1] = '\0' ;
            NewString.length = 1 ;

        } else if(Obj2.Sir!=nullptr)
        {

            NewString.Sir = new char [Obj2.length + 1 ] ;
            strcpy(NewString.Sir,Obj2.Sir);
            NewString.length = Obj2.length ;

        }
        return NewString ;



    }
    char & operator[](const int index)
    {
        cout << "operator 1" << endl ;
        static char s = '\0' ;
        if( index < length && index >= 0 )
        {
            return this->Sir[index];
        }
        throw -1 ;
    }
    const char & operator[](const int index) const
    {
        cout << "operator 2" << endl ;
        const char s = '\0' ;
        if( index < length && index >= 0 )
        {
            return this->Sir[index];
        }
        throw -1 ;



    }
    int getLength () const
    {
        if(this->Sir!=nullptr)
        {
            return this->length ;
        } else return 0 ;

    }
    String & insert (String & Obj , int pos )
    {
        if(pos<=this->length)
        {
            String copy(this->Sir);
            this->Sir = new char [ strlen(copy.Sir) + strlen(Obj.Sir) + 1 ] ;
            this->length = copy.length + Obj.length ;
            strcpy(this->Sir,copy.Sir);
            strcpy(this->Sir+pos , Obj.Sir) ;
            strcat(this->Sir,copy.Sir+pos);

        }
        return (*this);




    }
    const String & copy ( String & Obj , const int len , const int pos)
    {
        Obj.Sir = new char [len + 1] ;
        strcpy(Obj.Sir,this->Sir+pos);
        Obj.Sir[len] = '\0' ;
        Obj.length = len ;
        return Obj;

    }
    int find (const String & Obj) const
    {
        char * p ;
        p = strstr(this->Sir,Obj.Sir);
        if(p != NULL )
        {
            int pos1 = strlen(p) ;
            int pos2 = this->length ;
            pos2 = pos2 - pos1 ;
            return pos2 ;
        } else return -1;

    }
    String & erase (const int & pos , const int & len)
    {
        if( pos<=this->length && len <= this->length )
        {
            if( pos + len  <= this->length )
            {
                String copy(this->Sir);
                this->length = this->length - len ;
                this->Sir = new char [this->length + 1];
                strcpy(this->Sir,copy.Sir);
                strcpy(this->Sir+pos,copy.Sir+len+pos);
            }
        }
        return (*this);


    }
     ~ String ()
     {
        if(this->Sir!=NULL)
        {
            delete Sir ;
        }

     }
};

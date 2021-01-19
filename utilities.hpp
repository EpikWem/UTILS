
#ifndef MYLIB_HPP
#define MYLIB_HPP

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;


//========================
// NOMBRES
//========================

// ask to a value in the console
template <typename T>
T prompt (const string msg) {
    T x;
    cout << msg;
    cin >> x;
    return x;
}

// unsigned int
typedef unsigned int uint;

// test if n is divisible by d
template <typename T>
bool is_divisible (const T n, const T d) {
    return (n%d == 0);
}
// test if n is pair
template <typename T>
bool is_pair (const T &n) {
    return is_divisible(n, 2);
}


//========================
// TABLEAUX DYNAMIQUES
//========================

template <typename elem> // element
class dynarray {
private:
    uint l; // length
public:
    elem* a; // array
    // default constructor
    dynarray () {
        l = 0;
    }
    // length constructor
    dynarray (const uint length) {
        l = length;
        a = new elem[l];
    }
    // destructor
    ~dynarray () {
        delete[] a;
    }
    // affectation
    void operator= (const dynarray array) {
        l = array.l;
        for( uint i = 0; (i < l); i++ )
            a[i] = array.get(i);
    }
    // return value elem i
    elem operator[] (const uint i) const {
        return a[i];
    }
    // the length of the array
    uint length () const { 
        return l;
    }
    // return value elem i
    elem get (const uint i) const {
        return a[i];
    }
    // replace an element at i
    void set (const uint i, const elem e) {
        if (i >= l) {
            l++;
            a[l] = e;
        } else
            a[i] = e;
    }
    /*// add an element in the first free place of the array
    // return the indice
    uint add (const elem e) {
        for( uint i = 0; (i < l); i++ )
            set(i);
        return -1;
    }*/
    // concat two arrays
    dynarray<elem> operator++ (const dynarray<elem> a) {
        dynarray<elem> r(l+a.l);
        for( uint i = 0; (i < l); i++ )
            r[i] = get(i);
        for( uint i = 0; (i < a.l); i++ )
            r[l+i] = a.get(i);
        return r;
    }
    friend ostream& operator<< (ostream &os, const dynarray a) {
        cout << "{";
        for( uint i = 0; (i < length()); i++ )
            cout << " " << a.get(i);
        cout << " }";
        return os;
    }
    // apply a fonction on every elements
    void apply (elem (*function)(const elem)) {
        for( uint i = 0; (i < l); i++ )
            a[i] = function (a[i]);
    }
};

//========================
// VEC2
//========================

template <typename T>
class vec2 {
public:
    T x, y; // coords (x;y)
    // default constructor (0;0)
    vec2 () {
        x = 0; y = 0;
    }
    // coords constructor (x;y)
    vec2 (const T xin, const T yin) {
        x = xin; y = yin;
    }
    void operator= (const vec2 v) {
        x = v.x; y = v.y;
    }
    vec2 operator+ (const vec2 v) const {
        return vec2(x + v.x, y + v.y);
    }
    vec2 operator- (const vec2 v) const {
        return vec2(x - v.x, y - v.y);
    }
    vec2 operator* (const T f) const {
        return vec2(x*f, y*f);
    }
    vec2 operator/ (const T f) const {
        return vec2(x/f, y/f);
    }
    vec2 operator* (const vec2 v) const {
        return vec2(x*v.x - y*v.y, x*v.y + y*v.x );
    }
    friend ostream& operator<< (ostream &os, const vec2 v) {
        os << "(" << v.x << ";" << v.y << ")";
        return os;
    }
};

//========================
// PAIR
//========================

template <typename Tf, typename Ts>
class paire {
private:
    Tf f; Ts s;
public:
    paire (const Tf first, const Ts second) {
        f = first; s = second;
    }
    Tf first () const {
        return f;
    }
    Ts second () const {
        return s;
    }
    swap () {
        Tf t = f;
        f = s;
        s = t;
    }
    friend ostream& operator<< (ostream& os, const paire p) {
        os << "(" << p.first() << "," << p.second() << ")";
        return os;
    }
};

#endif

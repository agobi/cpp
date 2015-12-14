#include <iostream>
#include <functional>
#include "ffvec.h"
#include <string>
#include <vector>
#include "ffvec.h"
#include <set>

struct string_size_less: std::binary_function<std::string, std::string, bool>
{

  bool operator()( const std::string& a,
                   const std::string& b )
  {
    return a.size() < b.size();
  }

};

const unsigned int max = 1000u;

int main()
{
  int your_mark = 1;

  full_fledged_vector<std::string> vs;
  vs.push_front( "Hello" );
  vs.push_back( "World" );

  full_fledged_vector<int> v;
  v.push_back( 4 );
  v.push_front( 3 );
  v.push_back( 1 );
  const full_fledged_vector<int> cv = v;

  full_fledged_vector<int> t;
  for( int i = max - 1; i >= 0; --i )
  {
    t.push_front( i );
  }

  if( max == t.size() &&
      4 * max / 5 == &(t.at( 4 * max / 5 )) - &(t.at( 0 )) &&
      1 == cv.at( 2 ) &&
      2 == vs.size() &&
      3 == cv.size() &&
      0 == t.at( 0 ) )
  {
    your_mark = cv.at( 1 ) + v.at( 2 ) - cv.at( 0 );
  }

  if ( &std::vector<int>::pop_back != &full_fledged_vector<int>::pop_back ||
       &std::vector<int>::size != &full_fledged_vector<int>::size )
  {
    std::cout << "Use inheritance!";
    std::endl( std::cout );
  }
  else
  {
    t.pop_front();
    t.pop_front();
    ++t[ 0 ];
    vs.pop_front();
    v.sort();
    vs.sort();

    if ( "World" == vs[ 0 ] &&
         1 == vs.size() &&
         max - 2 == t.size() &&
         3 == v[ 1 ]&&
         1 == v[ 0 ] )
    {
      your_mark = t[ 0 ];
    }
  }

  /* 4-es
  vs.pop_back();
  vs.push_back( "Cobol" );
  vs.push_back( "C+" );
  vs.push_back( "C+" );
  vs.push_back( "Java" );
  vs.unique();
  vs.sort( string_size_less() );

  t.sort( std::greater<int>() );

  for( unsigned int i = 0; i < max; ++i )
  {
    v.push_front( 1 );
    v.push_back( 4 );
  }
  v.unique();
  if ( 3 == vs.size() &&
       "Cobol" == vs[ 2 ] &&
       max - 1 == t[ 0 ] &&
       3 == v.size() &&
       3 == v[ 1 ] )
  {
    your_mark = v[ 2 ];
  }
  */
  /* 5-os
  v.splice( v.begin(), t, t.begin() + 1, t.end() );

  std::string msg = "Hello";
  full_fledged_vector<char> mv( msg.begin(), msg.end() );

  std::set<int> s;
  s.insert( 7 );
  s.insert( 2 );
  full_fledged_vector<int> sv( s.begin(), s.end() );

  if ( 'l' == mv[ 3 ] &&
       2 == sv.size() &&
       7 == sv[ 1 ] &&
       1 == t.size() &&
       max == v.size() &&
       max - 2 == v[ 0 ] &&
       1 == v[ max - 3 ] )
  {
    your_mark = mv.size();
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}

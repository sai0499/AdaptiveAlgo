// ======================================================================
//
// Copyright (c) OVGU Magdeburg
//
// This software and related files are part of an Algorithm Engineering
// implementation project on adaptive sorting of polygon vertices,
// conducted at computer science department (FIN) at OVGU Magdeburg,
// Germany. All rights reserved.
//
// ======================================================================

#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <Point_2.h>

#include <Polygon.hpp>

typedef AE::Point_2<double>   Point_2;
typedef AE::Less_2<double>    Less_2;


int
main(int argc, char** argv)
{
  std::vector<Point_2>  P;
  std::vector<Point_2>  S;

  std::ifstream F(argv[1]);
  int n; F >> n;
  double x, y;
  for (int i=1; i<=n; ++i)
  { F >> x; F >> y;
    P.push_back( Point_2(x,y));
  }
  F.close();

  // reserve space for the sorted result
  std::copy(P.begin(), P.end(), std::back_inserter(S) );

  Less_2  xy_less;

  Polygon::sort( P.begin(), P.end(), S.begin(), xy_less);
  assert( std::is_sorted( S.begin(), S.end(), xy_less) );
  assert(!std::is_sorted( P.begin(), P.end(), xy_less) );

  return EXIT_SUCCESS;
}


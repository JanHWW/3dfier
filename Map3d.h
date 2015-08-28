
#ifndef __3dfier__Map3d__
#define __3dfier__Map3d__

#include "definitions.h"
#include "Polygon3d.h"


class Map3d
{
public:
  Map3d  ();
  ~Map3d ();

  bool add_possible_layer(std::string l);
  bool add_possible_layers(std::vector<std::string> ls);
  bool read_gml_file(std::string ifile, std::string idfield);

  bool construct_rtree();
  bool add_polygon3d(Polygon3d* pgn);
  bool add_point(Point2d* q);
  bool add_point(double x, double y, double z);

  unsigned long get_num_polygons();
     
private:
  std::vector<Polygon3d*>             _lsPolys;
  bgi::rtree< Value, bgi::rstar<16> > _rtree;
  std::vector<std::string>            _possible_layers;
};


#endif
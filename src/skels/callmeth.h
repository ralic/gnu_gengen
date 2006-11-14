/*
 * File automatically generated by
 * gengen 1.0 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef CALLMETH_GEN_CLASS_H
#define CALLMETH_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class callmeth_gen_class
{
 protected:
  string name;

 public:
  callmeth_gen_class()
  {
  }
  
  callmeth_gen_class(const string &_name) :
    name (_name)
  {
  }

  static void
  generate_string(const string &s, ostream &stream, unsigned int indent)
  {
    if (!indent || s.find('\n') == string::npos)
      {
        stream << s;
        return;
      }

    string::size_type pos;
    string::size_type start = 0;
    string ind (indent, ' ');
    while ( (pos=s.find('\n', start)) != string::npos)
      {
        stream << s.substr (start, (pos+1)-start);
        start = pos+1;
        if (start+1 <= s.size ())
          stream << ind;
      }
    if (start+1 <= s.size ())
      stream << s.substr (start);
  }

  void set_name(const string &_name)
  {
    name = _name;
  }

  void generate_callmeth(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "if (";
    generate_string (name, stream, indent + indent_str.length ());
    stream << ".size () > 0)";
    stream << "\n";
    stream << indent_str;
    stream << "  generate_string (";
    generate_string (name, stream, indent + indent_str.length ());
    stream << ", stream, indent + indent_str.length ());";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "  generate_";
    generate_string (name, stream, indent + indent_str.length ());
    stream << " (stream, indent + indent_str.length ());";
  }
};

#endif // CALLMETH_GEN_CLASS_H

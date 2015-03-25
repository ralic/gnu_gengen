/*
 * File automatically generated by
 * gengen 1.4.3rc by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef GENFUNCTION_LUA_GEN_CLASS_H
#define GENFUNCTION_LUA_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class genfunction_lua_gen_class
{
 protected:
  string assignfields;
  string geninstructions;
  string genname;
  string genparameters;

 public:
  genfunction_lua_gen_class()
  {
  }
  
  genfunction_lua_gen_class(const string &_assignfields, const string &_geninstructions, const string &_genname, const string &_genparameters) :
    assignfields (_assignfields), geninstructions (_geninstructions), genname (_genname), genparameters (_genparameters)
  {
  }

  virtual ~genfunction_lua_gen_class()
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

  virtual void generate_assignfields(ostream &stream, unsigned int indent) = 0;

  void set_assignfields(const string &_assignfields)
  {
    assignfields = _assignfields;
  }

  virtual void generate_geninstructions(ostream &stream, unsigned int indent) = 0;

  void set_geninstructions(const string &_geninstructions)
  {
    geninstructions = _geninstructions;
  }

  void set_genname(const string &_genname)
  {
    genname = _genname;
  }

  virtual void generate_genparameters(ostream &stream, unsigned int indent) = 0;

  void set_genparameters(const string &_genparameters)
  {
    genparameters = _genparameters;
  }

  void generate_genfunction_lua(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "\n";
    stream << indent_str;
    stream << "function generate_";
    stream << genname;
    stream << "(stream, record, indent)";
    stream << "\n";
    stream << indent_str;
    stream << "  local id = {}";
    stream << "\n";
    stream << indent_str;
    stream << "  local indent_str = \"\"";
    stream << "\n";
    stream << indent_str;
    stream << "  for i = 1, indent do";
    stream << "\n";
    stream << indent_str;
    stream << "    id[#id + 1] = ' '";
    stream << "\n";
    stream << indent_str;
    stream << "  end";
    stream << "\n";
    stream << indent_str;
    stream << "  indent_str = table.concat(id)";
    stream << "\n";
    stream << indent_str;
    stream << "  -- save context";
    stream << "\n";
    stream << indent_str;
    stream << "  local ctx = io.output()";
    stream << "\n";
    stream << indent_str;
    stream << "  io.output(stream)";
    stream << "\n";
    stream << indent_str;
    indent = 2;
    if (geninstructions.size () > 0)
      generate_string (geninstructions, stream, indent + indent_str.length ());
    else
      generate_geninstructions (stream, indent + indent_str.length ());
    indent = 0;
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "  -- restore context";
    stream << "\n";
    stream << indent_str;
    stream << "  io.output(ctx)";
    stream << "\n";
    stream << indent_str;
    stream << "end";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "function generatep_";
    stream << genname;
    stream << "(stream, indent";
    if (genparameters.size () > 0)
      generate_string (genparameters, stream, indent + indent_str.length ());
    else
      generate_genparameters (stream, indent + indent_str.length ());
    stream << ")";
    stream << "\n";
    stream << indent_str;
    stream << "  record = {}";
    stream << "\n";
    stream << indent_str;
    indent = 2;
    stream << "  ";
    if (assignfields.size () > 0)
      generate_string (assignfields, stream, indent + indent_str.length ());
    else
      generate_assignfields (stream, indent + indent_str.length ());
    indent = 0;
    stream << "\n";
    stream << indent_str;
    stream << "  generate_";
    stream << genname;
    stream << "(stream, record, indent)";
    stream << "\n";
    stream << indent_str;
    stream << "end";
    stream << "\n";
    stream << indent_str;
  }
};

#endif // GENFUNCTION_LUA_GEN_CLASS_H

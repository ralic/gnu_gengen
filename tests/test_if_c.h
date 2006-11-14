/*
 * File automatically generated by
 * gengen  by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef TEST_IF_GEN_STRUCT_H
#define TEST_IF_GEN_STRUCT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test_if_gen_struct
{
  short boolvar;
  int intvar;
  int intvarcomp;
  const char *mydef;
  const char *myvar;
  const char *stringvar;
  const char *stringvarcomp;
};

void
generate_test_if(FILE *stream, struct test_if_gen_struct *record, unsigned int indent);

void
generatep_test_if(FILE *stream, unsigned int indent, short boolvar, int intvar, int intvarcomp, const char *mydef, const char *myvar, const char *stringvar, const char *stringvarcomp);

char *
genstring_test_if(struct test_if_gen_struct *record, unsigned int indent);

char *
genstringp_test_if(unsigned int indent, short boolvar, int intvar, int intvarcomp, const char *mydef, const char *myvar, const char *stringvar, const char *stringvarcomp);

int
strcnt_test_if(struct test_if_gen_struct *record, unsigned int indent);

void
init_test_if_gen_struct(struct test_if_gen_struct *record);

void
generate_test_if(FILE *stream, struct test_if_gen_struct *record, unsigned int indent)
{
  char *indent_str;
  unsigned int i;

  indent_str = (char *) malloc (indent + 1);
  for (i = 0; i < indent; ++i)
    indent_str[i] = ' ';
  indent_str[indent] = '\0';
  indent = 0;

  fprintf (stream, "%s", "#include <iostream>");
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "using std::cout;");
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "using std::endl;");
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "#define MYVAR ");
  fprintf (stream, "%s", (record->myvar ? record->myvar : ""));
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "#define ");
  fprintf (stream, "%s", (record->mydef ? record->mydef : ""));
  fprintf (stream, "%s", " ");
  fprintf (stream, "%s", (record->myvar ? record->myvar : ""));
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "int");
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "main()");
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "{");
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  if (record->boolvar)
    {
      fprintf (stream, "%s", "  cout << \"boolvar test\" << endl;");
      fprintf (stream, "%s", "\n");
      fprintf (stream, "%s", indent_str);
    }
  else
    {
      if (( ( record->intvar < record->intvarcomp ) || ( record->intvar == 0 ) ))
        {
          fprintf (stream, "%s", "  cout << \"intvar test\" << endl;");
          fprintf (stream, "%s", "\n");
          fprintf (stream, "%s", indent_str);
        }
    }
  if (( ( record->stringvar && record->stringvarcomp && strcmp( record->stringvar, record->stringvarcomp ) < 0 ) || ( ( record->stringvar && strcmp( record->stringvar, "foo" ) != 0 ) && ( record->stringvar && strcmp( record->stringvar, "bara" ) < 0 ) ) ))
    {
      fprintf (stream, "%s", "  cout << \"stringvar value: \" << ");
      fprintf (stream, "%s", (record->stringvar ? record->stringvar : ""));
      fprintf (stream, "%s", " << endl;");
      fprintf (stream, "%s", "\n");
      fprintf (stream, "%s", indent_str);
    }
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "  return 0;");
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);
  fprintf (stream, "%s", "}");
  fprintf (stream, "%s", "\n");
  fprintf (stream, "%s", indent_str);

  free (indent_str);
}

void
generatep_test_if(FILE *stream, unsigned int indent, short boolvar, int intvar, int intvarcomp, const char *mydef, const char *myvar, const char *stringvar, const char *stringvarcomp)
{
  struct test_if_gen_struct record;
  
  record.boolvar = boolvar;
  record.intvar = intvar;
  record.intvarcomp = intvarcomp;
  record.mydef = mydef;
  record.myvar = myvar;
  record.stringvar = stringvar;
  record.stringvarcomp = stringvarcomp;

  generate_test_if (stream, &record, indent);
}

char *
genstring_test_if(struct test_if_gen_struct *record, unsigned int indent)
{
  char *indent_str, *output;
  unsigned int i;
  int len;

  indent_str = (char *) malloc (indent + 1);
  for (i = 0; i < indent; ++i)
    indent_str[i] = ' ';
  indent_str[indent] = '\0';

  len = strcnt_test_if (record, indent);
  output = (char *) malloc (len + 1);
  output[0] = '\0';

  strcat (output, "#include <iostream>");
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "using std::cout;");
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "using std::endl;");
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "#define MYVAR ");
  if (record->myvar) strcat (output, record->myvar);
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "#define ");
  if (record->mydef) strcat (output, record->mydef);
  strcat (output, " ");
  if (record->myvar) strcat (output, record->myvar);
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "int");
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "main()");
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "{");
  strcat (output, "\n");
  strcat (output, indent_str);
  if (record->boolvar)
    {
      strcat (output, "  cout << \"boolvar test\" << endl;");
      strcat (output, "\n");
      strcat (output, indent_str);
    }
  else
    {
      if (( ( record->intvar < record->intvarcomp ) || ( record->intvar == 0 ) ))
        {
          strcat (output, "  cout << \"intvar test\" << endl;");
          strcat (output, "\n");
          strcat (output, indent_str);
        }
    }
  if (( ( record->stringvar && record->stringvarcomp && strcmp( record->stringvar, record->stringvarcomp ) < 0 ) || ( ( record->stringvar && strcmp( record->stringvar, "foo" ) != 0 ) && ( record->stringvar && strcmp( record->stringvar, "bara" ) < 0 ) ) ))
    {
      strcat (output, "  cout << \"stringvar value: \" << ");
      if (record->stringvar) strcat (output, record->stringvar);
      strcat (output, " << endl;");
      strcat (output, "\n");
      strcat (output, indent_str);
    }
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "  return 0;");
  strcat (output, "\n");
  strcat (output, indent_str);
  strcat (output, "}");
  strcat (output, "\n");
  strcat (output, indent_str);

  free (indent_str);

  return output;
}

char *
genstringp_test_if(unsigned int indent, short boolvar, int intvar, int intvarcomp, const char *mydef, const char *myvar, const char *stringvar, const char *stringvarcomp)
{
  struct test_if_gen_struct record;
  
  record.boolvar = boolvar;
  record.intvar = intvar;
  record.intvarcomp = intvarcomp;
  record.mydef = mydef;
  record.myvar = myvar;
  record.stringvar = stringvar;
  record.stringvarcomp = stringvarcomp;

  return genstring_test_if (&record, indent);
}

int
strcnt_test_if(struct test_if_gen_struct *record, unsigned int indent)
{
  int length = 0;
  
  length += (record->myvar ? strlen (record->myvar) : 0) * 2;
  length += (record->mydef ? strlen (record->mydef) : 0) * 1;
if (record->boolvar)
    {
      

    }
  else
    {
      if (( ( record->intvar < record->intvarcomp ) || ( record->intvar == 0 ) ))
        {
          
      
        }
    }
if (( ( record->stringvar && record->stringvarcomp && strcmp( record->stringvar, record->stringvarcomp ) < 0 ) || ( ( record->stringvar && strcmp( record->stringvar, "foo" ) != 0 ) && ( record->stringvar && strcmp( record->stringvar, "bara" ) < 0 ) ) ))
    {
      length += (record->stringvar ? strlen (record->stringvar) : 0) * 1;
    }

  return length + 248;
}

void
init_test_if_gen_struct(struct test_if_gen_struct *record)
{
  record->boolvar = 0;
  record->intvar = 0;
  record->intvarcomp = 0;
  record->mydef = 0;
  record->myvar = 0;
  record->stringvar = 0;
  record->stringvarcomp = 0;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif // TEST_IF_GEN_STRUCT_H

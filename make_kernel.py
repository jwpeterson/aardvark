#!/usr/bin/env python

import sys
import os

name = ''

# Process command line args (0 is always the script name)
c = 1
while (c < len(sys.argv)):
    if (sys.argv[c] == '--basename' or sys.argv[c] == '--name'):
        name = sys.argv[c+1]
    elif (sys.argv[c] == '--help'):
        print("Usage: " + sys.argv[0] + " --name Foo")
        sys.exit(0)
    else:
        # If there's a trailing argument, treat it as the filename.
        name = sys.argv[c]

    c += 1

# Check that a valid name was specified.
if (not name):
    print("You must specify a Kernel name using the --name flag.")
    sys.exit(1)

# Check that we have a valid directory structure.
if (not os.path.isdir("include/kernels")):
    print("Creating \"include/kernels\" directory for you...")
    os.makedirs(os.path.join("include", "kernels"))

if (not os.path.isdir("src/kernels")):
    print("Creating \"src/kernels\" directory for you...")
    os.makedirs(os.path.join("src", "kernels"))

# name should have a capitalized first letter. The capitalize()
# utility will lowercase all other letters, so we only do it to the
# first character.
name = name[0].capitalize() + name[1:]

# Generate header and source names from name
header_name = "include/kernels/" + name + ".h"
source_name = "src/kernels/" + name + ".C"

# Print status message.
print("Creating header/src files: " + header_name + ", " + source_name)

# Generate include guard by upper casing the name
include_guard = name.upper()

# Write header file
f = open(header_name, "w")
f.write("#ifndef " + include_guard + "_H\n")
f.write("#define " + include_guard + "_H\n")
f.write("\n")
f.write("#include \"Kernel.h\"\n")
f.write("\n")
f.write("class " + name + ";\n")
f.write("\n")
f.write("template <>\n")
f.write("InputParameters validParams<" + name + ">();\n")
f.write("\n")
f.write("/**\n")
f.write(" * This kernel implements ...:\n")
f.write(" */\n")
f.write("class " + name + " : public Kernel\n")
f.write("{\n")
f.write("public:\n")
f.write("  " + name + "(const InputParameters & parameters);\n")
f.write("\n")
f.write("protected:\n")
f.write("  virtual Real computeQpResidual() override;\n")
f.write("\n")
f.write("  virtual Real computeQpJacobian() override;\n")
f.write("};\n")
f.write("\n")
f.write("#endif /* " + include_guard + "_H */\n")

# Write source file
f = open(source_name, "w")
f.write("#include \"" + name + ".h\"\n")
f.write("\n")
f.write("registerMooseObject(\"MooseApp\", " + name + ");\n")
f.write("\n")
f.write("template <>\n")
f.write("InputParameters\n")
f.write("validParams<" + name + ">()\n")
f.write("{\n")
f.write("  InputParameters params = validParams<Kernel>();\n")
f.write("  params.addClassDescription(\"This class ...\");\n")
f.write("  return params;\n")
f.write("}\n")
f.write("\n")
f.write(name + "::" + name + "(const InputParameters & parameters) : Kernel(parameters) {}\n")
f.write("\n")
f.write("Real\n")
f.write(name + "::computeQpResidual()\n")
f.write("{\n")
f.write("  return ...;\n")
f.write("}\n")
f.write("\n")
f.write("Real\n")
f.write(name + "::computeQpJacobian()\n")
f.write("{\n")
f.write("  return ...;\n")
f.write("}\n")

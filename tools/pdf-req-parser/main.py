#!/usr/bin/env python3

from autosar_pdf_parser import SimpleRequirementsParser
import simplejson
import sys

if __name__ == "__main__":
    verbose = False
    input_dir_path = None
    output_file_path = None

    for i in range(len(sys.argv)):
        arg = sys.argv[i]
        if arg in ('-v', '-verbose'):
            verbose = True
        elif arg in ('-i', '-in'):
            input_dir_path = sys.argv[i + 1]
        elif arg in ('-o', '-out'):
            output_file_path = sys.argv[i + 1]

    if (not input_dir_path) or (not output_file_path):
        print('Usage:')
        print('\t -v, -verbose  --  print log')
        print('\t -i, -in       --  input directory path')
        print('\t -o, -out      --  output json file path')
        sys.exit(-1)

    if not SimpleRequirementsParser.is_input_path_correct(input_dir_path):
        print('input.json file does not exist.')
        sys.exit(-2)

    autosar_parser = SimpleRequirementsParser(input_dir_path, verbose=verbose)

    with open(output_file_path, 'w+') as file:
        file.write(simplejson.dumps(autosar_parser.requirements, indent=4))

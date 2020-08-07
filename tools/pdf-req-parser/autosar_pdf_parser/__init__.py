import os
import simplejson
from PyPDF2 import PdfFileReader


class SimpleRequirementsParser(object):
    def __init__(self, path, verbose=False):
        self.input_directory = path
        self.input_list_file = '{}/input.json'.format(path)
        self.input_list = SimpleRequirementsParser.get_input_list(self.input_list_file)
        self.verbose = verbose
        self.requirements = {}
        self.parse()

    @staticmethod
    def is_input_path_correct(path):
        input_list_file = '{}/input.json'.format(path)
        return os.path.isfile(input_list_file)

    @staticmethod
    def get_input_list(path):
        with open(path, 'rb') as file:
            return simplejson.load(file)

    @staticmethod
    def find_all_entries_between(text, p, q, required_char=None):
        entries = []
        entry = ''
        found = False
        for ch in text:
            if ch == p:
                found = True
                entry += ch
            elif ch == q:
                entry += ch
                if not required_char:
                    entries.append(entry.replace('{}{}'.format(p, p), p).replace('{}{}'.format(q, q), q))
                else:
                    if required_char in entry:
                        entries.append(entry.replace('{}{}'.format(p, p), p).replace('{}{}'.format(q, q), q))
                entry = ''
                found = False
            if found:
                entry += ch
        return entries

    def log(self, text):
        if self.verbose:
            print(text)

    def parse(self):
        for input_entry in self.input_list:
            file_path = '{}/{}'.format(self.input_directory, input_entry['filename'])
            self.log('Processing new file: {}'.format(file_path))
            with open(file_path, 'rb') as f:
                self.requirements[input_entry['filename']] = {}  # new key in requirements list
                pdf = PdfFileReader(f)
                entries = []
                for page_num in range(input_entry['first_page'] - 1, input_entry['last_page']):
                    self.log('\tPage {}/{}'.format(page_num + 1, input_entry['last_page']))
                    page = pdf.getPage(page_num)
                    text = page.extractText().replace('\n', '')
                    entries.extend(SimpleRequirementsParser.find_all_entries_between(text, '[', ']', required_char='_'))

                # only for SWS files (temporary)
                # todo: implement other types (_RS_, _TPS_)
                current_rs = None
                for entry in entries:
                    if 'RS' in entry:
                        current_rs = entry
                        self.requirements[input_entry['filename']][current_rs] = {}
                    elif 'SWS' in entry:
                        self.requirements[input_entry['filename']][current_rs][entry] = {'more_data': 'soon'}

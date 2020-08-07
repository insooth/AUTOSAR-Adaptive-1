# Autosar Adaptive PDF Requirements Parser

# Installation
docker build -t autosar-adaptive-req-pdf-parser .

# Usage
docker run -v <requirements_directory_path>:/input autosar-adaptive-req-pdf-parser -verbose -in <requirements_directory_path> -out <requirements_directory_path>/output.json

<requirements_directory_path> - all PDF files with requirements and input.json file should be there

### input.json
It is a file with description of requirements PDF files, e.g.:


```javascript
[
    {
        "filename": "AUTOSAR_SWS_AdaptivePlatformTypes.pdf",
        "first_page": 10,
        "last_page": 10
    },
    {
        "filename": "AUTOSAR_SWS_CommunicationManagement.pdf",
        "first_page": 14,
        "last_page": 42
    }
]

// first_page - number of first page with Requirements Tracing (table)
// last_page - number of last page with Requirements Tracing (table)

```

After all output.json file should be created in <requirements_directory_path>.
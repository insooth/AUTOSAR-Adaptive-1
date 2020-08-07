FROM ubuntu:16.04

RUN apt-get update && apt-get install python3 python3-pip -y
RUN pip3 install PyPDF2 simplejson

ENTRYPOINT ["python3", "main.py"]
COPY . .

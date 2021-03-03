# Upload
curl ftp://EXTERNAL_IP:21 --ssl -k --user admin -T [file]
(password : pass)
# /var/ftps/user/admin/	에 upload됨 확인

# Download
curl -u admin:pass 'ftp://EXTERNAL_IP:21/[file]' --ssl -k  -o [output_file_name]
# file : testfile.txt

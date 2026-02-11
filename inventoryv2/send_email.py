import smtplib
from email.mime.text import MIMEText
import sys

sender_email = "pointbreak123455@gmail.com"
app_password = "lytaymuqghubguro"   # 🔴 PUT YOUR GMAIL APP PASSWORD HERE
receiver_email = "pointbreak123455@gmail.com"

if len(sys.argv) < 4:
    exit()

item_id = sys.argv[1]
item_name = sys.argv[2]
stock_left = sys.argv[3]

subject = "LOW STOCK ALERT 🚨"

body = f"""
Low Stock Alert!

Item ID: {item_id}
Item Name: {item_name}
Stock Remaining: {stock_left}

Please restock immediately.
"""

msg = MIMEText(body)
msg["Subject"] = subject
msg["From"] = sender_email
msg["To"] = receiver_email

try:
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.starttls()
    server.login(sender_email, app_password)
    server.send_message(msg)
    server.quit()
except Exception as e:
    pass

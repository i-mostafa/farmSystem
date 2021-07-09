const express = require("express");
const nodemailer = require("nodemailer");

const app = express();
var query = {};
const testAccount = {
  user: "smartfarm520@gmail.com",
  pass: "Smartfarm**520",
};
// create reusable transporter object using the default SMTP transport
let transporter = nodemailer.createTransport({
  service: "gmail",
  auth: {
    user: testAccount.user, // generated ethereal user
    pass: testAccount.pass, // generated ethereal password
  },
});
const snedMail = async (query) =>
  await transporter.sendMail({
    from: "smartfarm520@gmail.com", // sender address
    to: "ayaslama300@gmail.com", // list of receivers
    subject: "farm system readnigs", // Subject line
    text: JSON.stringify(query, null, 4), // plain text body
  });

app.get("/", (req, res, next) => {
  res.status(200).json(query);
});

app.get("/mail", (req, res, next) => {
  query = { ...req.query };
  console.log(query);
  snedMail(query);
  res.status(200).send("ok");
});

app.listen(5050, () => {
  console.log("server is running");
});

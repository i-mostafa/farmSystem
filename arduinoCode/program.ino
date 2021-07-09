void run_program(){
  readData ();
  validate_data();
  print_data();
  control_pumbs();
  control_fans();
  send_report_mail();
}

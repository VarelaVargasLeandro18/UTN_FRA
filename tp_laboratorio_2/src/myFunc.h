/* \brief ask for a number and checks if is between two values.
 * \param char* msg Message to shown to the user.
 * \param float less minor value.
 * \param float mayor mayor value.
 * \param char* al_msg Message to shown if the user input is not between the given values.
 * \return float number enter by the user.
 */
float get_nr_bt (char* msg, float less, float mayor, char* al_msg);

/* \brief ask for a number.
 * \param char* msg message that will be shown to the user.
 * \return float value that the user inputs.
 */
float get_number (char* msg);

/* \brief get and check if an option is valid.
 * \param int minor minor number.
 * \param int Mayor Mayor number.
 * \param int amEmployee amount of Employees that are already in.
 */
int get_option (int minor, int Mayor, int amEmployee);

/* \brief Eliminate a character in a String.
 * \param char* str to search for the character.
 * \param char chara character to remove.
 * \return void
 */
void str_eliminate (char str[], int len, char chara);

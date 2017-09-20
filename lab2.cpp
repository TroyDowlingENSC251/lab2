// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and Integrity related policies as outlined in
// the syllabus.
//
// _____Troy Dowling____ ____2017-09-20____
//
// ____301216033______

#include <iostream>     // IO stream library
#include <algorithm>    // ::transform
#include <string>       // STL strings
#include <list>         // Used for vowel membership list

/***
 * main() takes two string inputs from the user representing their first and
 * last name. It then downcases via transformation, applies the rules of Pig
 * Latin, proper cases, and outputs to user.
 *
 * Pig Latin Rule #1: If a word starts with a consonant, move it to the end and
 * add "ay".
 *
 * Pig Latin Rule #2: If a word starts with a vowel, add "way" to the end.
 ***/
int main(void)
{
    // Declare firstname and lastname strings.
    std::string firstname, lastname;

    // Request input from user.
    std::cout << "First name: " << std::flush;
    std::cin >> firstname;
    std::cout << "Last name:  " << std::flush;
    std::cin >> lastname;

    // Downcase firstname via in-place transformation
    std::transform(firstname.begin(), // Input start iterator
                   firstname.end(),   // Input end iterator
                   firstname.begin(), // Output start iterator
                   ::tolower);        // Scope-resolved operator

    // Downcase lastname via in-place transformation
    std::transform(lastname.begin(),  // Input start iterator
                   lastname.end(),    // Input end iterator
                   lastname.begin(),  // Output start iterator
                   ::tolower);        // Scope-resolved operator

    // Assert that input is alpha only.
    std::string alpha = "abcdefghijklmnopqrstuvwxyz ";  // Alpha and space
    if(firstname.find_first_not_of(alpha) != std::string::npos)
    {
        // Firstname contains non-alpha characters.
        std::cout <<
            "Firstname must only contain alpha characters and space." <<
            std::endl;
        // Terminate unsuccessfully
        return EXIT_FAILURE;
    }
    if(lastname.find_first_not_of(alpha) != std::string::npos)
    {
        // Lastname contains non-alpha characters.
        std::cout <<
            "Lastname must only contain alpha characters and space." <<
            std::endl;
        // Terminate unsuccessfully
        return EXIT_FAILURE;
    }

    // Declare list of vowels
    std::list<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    // Check if first character in firstname is a vowel using automatic iterator
    auto it = std::find(vowels.begin(), vowels.end(), firstname.front());
    if(it == vowels.end())
    {
        // First letter is a consonant, apply rule #1.
        firstname.push_back(firstname.front()); // Stick first letter on end
        firstname.erase(0, 1);                  // Drop first character
        firstname += "ay";                      // Append "ay" to end
    }
    else
    {
        // First letter is a vowel
        firstname += "way";
    }

    // Check if first character in lastname is a vowel using automatic iterator
    it = std::find(vowels.begin(), vowels.end(), lastname.front());
    if(it == vowels.end())
    {
        // First letter is a consonant, apply rule #1.
        lastname.push_back(lastname.front());   // Stick first letter on end
        lastname.erase(0, 1);                   // Drop first character
        lastname += "ay";                       // Append "ay" to end
    }
    else
    {
        // First letter is a vowel
        lastname += "way";
    }

    // Proper case the full name.
    firstname[0] = std::toupper(firstname.front());
    lastname[0] = std::toupper(lastname.front());

    // Spec asks for full name in one string
    std::string fullname = firstname + " " + lastname;

    // Print the full name to the terminal.
    std::cout << fullname << std::endl;

    // All done! Let the kernel know.
    return EXIT_SUCCESS;
}

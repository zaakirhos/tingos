using System;
using JokesLib;


namespace Jokes
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("");
            Joke horse = new Joke
            {
                Question = "",
                Answer = "A horse with no legs"
            };
        }
    }
}

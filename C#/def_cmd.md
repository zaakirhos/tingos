## Setup

- Create a root folder that will holds a Solution and one or multiple projects
- Create Solution
  - A 'container' that holds multiple projects and connect each other
  - _dotnet new sln_ [-n name]_
    - defaults to the current dir name if not given
  
- Create UI project
  - This is where the most of the frontend will be done
  - _dotnet new console_ [ -n name]_
    - defaults to the current dir name if not given
    - the type could be _console_ or other
  
- Create a library project for the UI
  - This is where most of the backend will happen
  - _dotnet new classlib_ [-n name]
  
- Create more projects if needed
  
- Add the projects to the Solution
  - _dotnet sln_ [name.sln] _add_ name/name.csproj
    - _name.sln_ is defaults to the current solution in the root folder
  - _dotnet sln_ [name.sln] _add_ *\*/\*.csproj
    - Globing pattern
    - Adds all the projects to the current or given solution
  
- Reference between projects
  - _dotnet add_ project1Name/project1Name.csproj _reference_ project2Name/project2Name.csproj
    - project1Name owns the reference

- Run project
  - _cd_ to a project and do _dotnet run_
  
- Start coding!!!
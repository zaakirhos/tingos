## Commands
- _django-admin startproject_ <name>
  - <name> the name of the project
- _python manage.py startapp_ <name>
  - <name> the name of the app
  - Must add to INSTALLED_APPS in settings.py for     migrations
  - Each project can have multiple apps
- _python manage.py runserver_ [options]
  - Starts the server
- _python manage.py makeimigration_
  - prepares the migration of models
- _python manage.py sqlmigrate_
  - 
- _python manage.py migrate_
  - finally migrate the models
- _python manage.py collectstatic_
  - collect all the static files 

## Django terms:
- templates
  - 

## Django features
- By default it comes with sqlLite

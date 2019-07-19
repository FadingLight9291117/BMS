#ifndef _INC_FACTORY_
#define _INC_FACTORY_

#include"InsertDAO.h"
#include"QueryDAO.h"
#include"RemoveDAO.h"
#include"UpdateDAO.h"


class DAOFactory
{
public:
	DAOFactory() {}
	InsertDAO* createInsertDAO();
	RemoveDAO* createRemoveDAO();
	UpdateDAO* createUpdateDAO();
	QueryDAO *createQueryDAO();

};

InsertDAO* DAOFactory::createInsertDAO()
{
	return new InsertDAO();
}

RemoveDAO* DAOFactory::createRemoveDAO()
{
	return new RemoveDAO();
}

UpdateDAO* DAOFactory::createUpdateDAO()
{
	return new UpdateDAO();
}

QueryDAO *DAOFactory::createQueryDAO()
{
	return new QueryDAO();
}



#endif // !_INC_FACTORY_

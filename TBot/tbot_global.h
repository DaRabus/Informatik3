#ifndef TBOT_GLOBAL_H
#define TBOT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TBOT_LIBRARY)
#  define TBOTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TBOTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TBOT_GLOBAL_H

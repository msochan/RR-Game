#include "stdafx.h"
#include "Object.h"


void Object::Render()
{
	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	float m_amb[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	float m_dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float m_spe[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_spe);

	glBindTexture(GL_TEXTURE_2D, this->objectLoader->GetObjectTexture());

	glPushMatrix();

	glTranslatef(x, y, z);
	glScalef(this->size, this->size, this->size);
	glRotatef(this->angle, 0, 1, 0);
	glCallList(this->objectLoader->GetObjectModel());

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}



struct Vector3f
{
    union {
        float x = 0.0f;
        float r;
    };

    union {
        float y = 0.0f;
        float g;
    };

    union {
        float z = 0.0f;
        float b;
    };

    Vector3f() {}

    Vector3f(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    Vector3f(const float* pFloat)
    {
        x = pFloat[0];
        y = pFloat[1];
        z = pFloat[2];
    }

#ifdef true

  Vector3f(const glm::vec3& v)
    {
        x = v[0];
        y = v[1];
        z = v[2];
    }


 void InitRandom(const Vector3f& MinVal, const Vector3f& MaxVal);

    void InitBySphericalCoords(float Radius, float Pitch, float Heading)
    {
        x = Radius * cosf(ToRadian(Pitch)) * sinf(ToRadian(Heading));
        y = -Radius * sinf(ToRadian(Pitch));
        z = Radius * cosf(ToRadian(Pitch)) * cosf(ToRadian(Heading));
    }

    Vector3f(float f)
    {
        x = y = z = f;
    }

    Vector3f(const Vector4f& v);

    Vector3f& operator+=(const Vector3f& r)
    {
        x += r.x;
        y += r.y;
        z += r.z;

        return *this;
    }

    Vector3f& operator-=(const Vector3f& r)
    {
        x -= r.x;
        y -= r.y;
        z -= r.z;

        return *this;
    }

    Vector3f& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;

        return *this;
    }

    bool operator==(const Vector3f& r)
    {
        return ((x == r.x) && (y == r.y) && (z == r.z));
    }

    bool operator!=(const Vector3f& r)
    {
        return !(*this == r);
    }

    operator const float* () const
    {
        return &(x);
    }

    Vector3f Cross(const Vector3f& v) const;

    float Dot(const Vector3f& v) const
    {
        float ret = x * v.x + y * v.y + z * v.z;
        return ret;
    }

    float Distance(const Vector3f& v) const
    {
        float delta_x = x - v.x;
        float delta_y = y - v.y;
        float delta_z = z - v.z;
        float distance = sqrtf(delta_x * delta_x + delta_y * delta_y + delta_z * delta_z);
        return distance;
    }

    float Length() const
    {
        float len = sqrtf(x * x + y * y + z * z);
        return len;
    }

    bool IsZero() const
    {
        return ((x + y + z) == 0.0f);
    }

    Vector3f& Normalize();

    void Rotate(float Angle, const Vector3f& Axis);

    Vector3f Negate() const;

    void Print(bool endl = true) const
    {
        printf("(%f, %f, %f)", x, y, z);

        if (endl) {
            printf("\n");
        }
    }

    float* data()
    {
        return &x;
    }

    void SetAll(float f)
    {
        x = y = z = 0.0f;
    }

    void SetZero()
    {
        SetAll(0.0f);
    }


    glm::vec3 ToGLM() const
    {
        glm::vec3 ret(x, y, z);
        return ret;
    }
#endif
};
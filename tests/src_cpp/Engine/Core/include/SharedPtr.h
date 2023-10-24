/*
 *  Copyright (C) 2020-2021 Xios
 *
 *  This file is part of Hoopoe-Engine.
 *
 *  Hoopoe-Engine is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Hoopoe-Engine is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Hoopoe-Engine.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef __HOOPOE_ENGINE_CORE_SHAREDPTR_H__
#define __HOOPOE_ENGINE_CORE_SHAREDPTR_H__

#include <memory>

namespace Hoopoe 
{

template<class T> 
class SharedPtr : public std::shared_ptr<T>
{
public:
    SharedPtr(std::nullptr_t) {}
    SharedPtr() {}
    template<class Y>
    explicit SharedPtr(Y* ptr) : std::shared_ptr<T>(ptr) {}
    template<class Y, class Deleter >
    SharedPtr(Y* ptr, Deleter d) : std::shared_ptr<T>(ptr, d) {}
    SharedPtr(const SharedPtr& r) : std::shared_ptr<T>(r) {}
    template<class Y>
    SharedPtr(const SharedPtr<Y>& r) : std::shared_ptr<T>(r) {}

    // implicit conversion from and to shared_ptr
    template<class Y>
    SharedPtr(const std::shared_ptr<Y>& r) : std::shared_ptr<T>(r) {}
    operator const std::shared_ptr<T>&() { return static_cast<std::shared_ptr<T>&>(*this); }
    SharedPtr<T>& operator=(const Hoopoe::SharedPtr<T>& rhs) { std::shared_ptr<T>::operator=(rhs); return *this; }
    // so swig recognizes it should forward the operators
    T* operator->() const { return std::shared_ptr<T>::operator->(); }

    template<typename Y>
    SharedPtr<Y> staticCast() const { return std::static_pointer_cast<Y>(*this); }

    template<typename Y>
    SharedPtr<Y> dynamicCast() const { return std::dynamic_pointer_cast<Y>(*this); }

    void bind(T* rep) { std::shared_ptr<T>::reset(rep); }
    uint useCount() const { return std::shared_ptr<T>::use_count(); }
    T* getPointer() const { return std::shared_ptr<T>::get(); }
    bool isNull(void) const { return !std::shared_ptr<T>::operator bool(); }
    void setNull() { std::shared_ptr<T>::reset(); }
}; // SharedPtr

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_SHAREDPTR_H__
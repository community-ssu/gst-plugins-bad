/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GST_VIDEODROP_H__
#define __GST_VIDEODROP_H__

#include <gst/gst.h>

G_BEGIN_DECLS

#define GST_TYPE_VIDEODROP \
  (gst_videodrop_get_type())
#define GST_VIDEODROP(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_VIDEODROP,GstVideodrop))
#define GST_VIDEODROP_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_VIDEODROP,GstVideodropClass))
#define GST_IS_VIDEODROP(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_VIDEODROP))
#define GST_IS_VIDEODROP_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_VIDEODROP))

typedef struct _GstVideodrop GstVideodrop;
typedef struct _GstVideodropClass GstVideodropClass;

struct _GstVideodrop {
  GstElement element;

  GstPad *sinkpad, *srcpad;

  /* video state */
  gboolean inited;
  gfloat from_fps,
         to_fps;
  gfloat speed;
  guint64 pass, total, time_adjust;
};

struct _GstVideodropClass {
  GstElementClass parent_class;
};

GType gst_videodrop_get_type(void);

G_END_DECLS

#endif /* __GST_VIDEODROP_H__ */

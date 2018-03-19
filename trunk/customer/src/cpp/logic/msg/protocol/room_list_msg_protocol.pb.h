// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: room_list_msg_protocol.proto

#ifndef PROTOBUF_room_5flist_5fmsg_5fprotocol_2eproto__INCLUDED
#define PROTOBUF_room_5flist_5fmsg_5fprotocol_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace gamer {
namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_room_5flist_5fmsg_5fprotocol_2eproto();
void protobuf_AssignDesc_room_5flist_5fmsg_5fprotocol_2eproto();
void protobuf_ShutdownFile_room_5flist_5fmsg_5fprotocol_2eproto();

class RoomItemMsgProtocol;
class RoomListMsgProtocol;

// ===================================================================

class RoomItemMsgProtocol : public ::google::protobuf::Message {
 public:
  RoomItemMsgProtocol();
  virtual ~RoomItemMsgProtocol();

  RoomItemMsgProtocol(const RoomItemMsgProtocol& from);

  inline RoomItemMsgProtocol& operator=(const RoomItemMsgProtocol& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RoomItemMsgProtocol& default_instance();

  void Swap(RoomItemMsgProtocol* other);

  // implements Message ----------------------------------------------

  RoomItemMsgProtocol* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RoomItemMsgProtocol& from);
  void MergeFrom(const RoomItemMsgProtocol& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 room_id = 1;
  inline bool has_room_id() const;
  inline void clear_room_id();
  static const int kRoomIdFieldNumber = 1;
  inline ::google::protobuf::uint32 room_id() const;
  inline void set_room_id(::google::protobuf::uint32 value);

  // optional uint32 score_type = 2;
  inline bool has_score_type() const;
  inline void clear_score_type();
  static const int kScoreTypeFieldNumber = 2;
  inline ::google::protobuf::uint32 score_type() const;
  inline void set_score_type(::google::protobuf::uint32 value);

  // optional uint32 cost_score = 3;
  inline bool has_cost_score() const;
  inline void clear_cost_score();
  static const int kCostScoreFieldNumber = 3;
  inline ::google::protobuf::uint32 cost_score() const;
  inline void set_cost_score(::google::protobuf::uint32 value);

  // optional uint32 min_score = 4;
  inline bool has_min_score() const;
  inline void clear_min_score();
  static const int kMinScoreFieldNumber = 4;
  inline ::google::protobuf::uint32 min_score() const;
  inline void set_min_score(::google::protobuf::uint32 value);

  // optional uint32 base_score = 5;
  inline bool has_base_score() const;
  inline void clear_base_score();
  static const int kBaseScoreFieldNumber = 5;
  inline ::google::protobuf::uint32 base_score() const;
  inline void set_base_score(::google::protobuf::uint32 value);

  // optional uint32 cur_players_num = 6;
  inline bool has_cur_players_num() const;
  inline void clear_cur_players_num();
  static const int kCurPlayersNumFieldNumber = 6;
  inline ::google::protobuf::uint32 cur_players_num() const;
  inline void set_cur_players_num(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:gamer.protocol.RoomItemMsgProtocol)
 private:
  inline void set_has_room_id();
  inline void clear_has_room_id();
  inline void set_has_score_type();
  inline void clear_has_score_type();
  inline void set_has_cost_score();
  inline void clear_has_cost_score();
  inline void set_has_min_score();
  inline void clear_has_min_score();
  inline void set_has_base_score();
  inline void clear_has_base_score();
  inline void set_has_cur_players_num();
  inline void clear_has_cur_players_num();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 room_id_;
  ::google::protobuf::uint32 score_type_;
  ::google::protobuf::uint32 cost_score_;
  ::google::protobuf::uint32 min_score_;
  ::google::protobuf::uint32 base_score_;
  ::google::protobuf::uint32 cur_players_num_;
  friend void  protobuf_AddDesc_room_5flist_5fmsg_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_room_5flist_5fmsg_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_room_5flist_5fmsg_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static RoomItemMsgProtocol* default_instance_;
};
// -------------------------------------------------------------------

class RoomListMsgProtocol : public ::google::protobuf::Message {
 public:
  RoomListMsgProtocol();
  virtual ~RoomListMsgProtocol();

  RoomListMsgProtocol(const RoomListMsgProtocol& from);

  inline RoomListMsgProtocol& operator=(const RoomListMsgProtocol& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RoomListMsgProtocol& default_instance();

  void Swap(RoomListMsgProtocol* other);

  // implements Message ----------------------------------------------

  RoomListMsgProtocol* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RoomListMsgProtocol& from);
  void MergeFrom(const RoomListMsgProtocol& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 player_id = 1;
  inline bool has_player_id() const;
  inline void clear_player_id();
  static const int kPlayerIdFieldNumber = 1;
  inline ::google::protobuf::uint32 player_id() const;
  inline void set_player_id(::google::protobuf::uint32 value);

  // repeated .gamer.protocol.RoomItemMsgProtocol room_list = 2;
  inline int room_list_size() const;
  inline void clear_room_list();
  static const int kRoomListFieldNumber = 2;
  inline const ::gamer::protocol::RoomItemMsgProtocol& room_list(int index) const;
  inline ::gamer::protocol::RoomItemMsgProtocol* mutable_room_list(int index);
  inline ::gamer::protocol::RoomItemMsgProtocol* add_room_list();
  inline const ::google::protobuf::RepeatedPtrField< ::gamer::protocol::RoomItemMsgProtocol >&
      room_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::gamer::protocol::RoomItemMsgProtocol >*
      mutable_room_list();

  // @@protoc_insertion_point(class_scope:gamer.protocol.RoomListMsgProtocol)
 private:
  inline void set_has_player_id();
  inline void clear_has_player_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::gamer::protocol::RoomItemMsgProtocol > room_list_;
  ::google::protobuf::uint32 player_id_;
  friend void  protobuf_AddDesc_room_5flist_5fmsg_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_room_5flist_5fmsg_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_room_5flist_5fmsg_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static RoomListMsgProtocol* default_instance_;
};
// ===================================================================


// ===================================================================

// RoomItemMsgProtocol

// required uint32 room_id = 1;
inline bool RoomItemMsgProtocol::has_room_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RoomItemMsgProtocol::set_has_room_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RoomItemMsgProtocol::clear_has_room_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RoomItemMsgProtocol::clear_room_id() {
  room_id_ = 0u;
  clear_has_room_id();
}
inline ::google::protobuf::uint32 RoomItemMsgProtocol::room_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.RoomItemMsgProtocol.room_id)
  return room_id_;
}
inline void RoomItemMsgProtocol::set_room_id(::google::protobuf::uint32 value) {
  set_has_room_id();
  room_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.RoomItemMsgProtocol.room_id)
}

// optional uint32 score_type = 2;
inline bool RoomItemMsgProtocol::has_score_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RoomItemMsgProtocol::set_has_score_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RoomItemMsgProtocol::clear_has_score_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RoomItemMsgProtocol::clear_score_type() {
  score_type_ = 0u;
  clear_has_score_type();
}
inline ::google::protobuf::uint32 RoomItemMsgProtocol::score_type() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.RoomItemMsgProtocol.score_type)
  return score_type_;
}
inline void RoomItemMsgProtocol::set_score_type(::google::protobuf::uint32 value) {
  set_has_score_type();
  score_type_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.RoomItemMsgProtocol.score_type)
}

// optional uint32 cost_score = 3;
inline bool RoomItemMsgProtocol::has_cost_score() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RoomItemMsgProtocol::set_has_cost_score() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RoomItemMsgProtocol::clear_has_cost_score() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RoomItemMsgProtocol::clear_cost_score() {
  cost_score_ = 0u;
  clear_has_cost_score();
}
inline ::google::protobuf::uint32 RoomItemMsgProtocol::cost_score() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.RoomItemMsgProtocol.cost_score)
  return cost_score_;
}
inline void RoomItemMsgProtocol::set_cost_score(::google::protobuf::uint32 value) {
  set_has_cost_score();
  cost_score_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.RoomItemMsgProtocol.cost_score)
}

// optional uint32 min_score = 4;
inline bool RoomItemMsgProtocol::has_min_score() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void RoomItemMsgProtocol::set_has_min_score() {
  _has_bits_[0] |= 0x00000008u;
}
inline void RoomItemMsgProtocol::clear_has_min_score() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void RoomItemMsgProtocol::clear_min_score() {
  min_score_ = 0u;
  clear_has_min_score();
}
inline ::google::protobuf::uint32 RoomItemMsgProtocol::min_score() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.RoomItemMsgProtocol.min_score)
  return min_score_;
}
inline void RoomItemMsgProtocol::set_min_score(::google::protobuf::uint32 value) {
  set_has_min_score();
  min_score_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.RoomItemMsgProtocol.min_score)
}

// optional uint32 base_score = 5;
inline bool RoomItemMsgProtocol::has_base_score() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void RoomItemMsgProtocol::set_has_base_score() {
  _has_bits_[0] |= 0x00000010u;
}
inline void RoomItemMsgProtocol::clear_has_base_score() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void RoomItemMsgProtocol::clear_base_score() {
  base_score_ = 0u;
  clear_has_base_score();
}
inline ::google::protobuf::uint32 RoomItemMsgProtocol::base_score() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.RoomItemMsgProtocol.base_score)
  return base_score_;
}
inline void RoomItemMsgProtocol::set_base_score(::google::protobuf::uint32 value) {
  set_has_base_score();
  base_score_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.RoomItemMsgProtocol.base_score)
}

// optional uint32 cur_players_num = 6;
inline bool RoomItemMsgProtocol::has_cur_players_num() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void RoomItemMsgProtocol::set_has_cur_players_num() {
  _has_bits_[0] |= 0x00000020u;
}
inline void RoomItemMsgProtocol::clear_has_cur_players_num() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void RoomItemMsgProtocol::clear_cur_players_num() {
  cur_players_num_ = 0u;
  clear_has_cur_players_num();
}
inline ::google::protobuf::uint32 RoomItemMsgProtocol::cur_players_num() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.RoomItemMsgProtocol.cur_players_num)
  return cur_players_num_;
}
inline void RoomItemMsgProtocol::set_cur_players_num(::google::protobuf::uint32 value) {
  set_has_cur_players_num();
  cur_players_num_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.RoomItemMsgProtocol.cur_players_num)
}

// -------------------------------------------------------------------

// RoomListMsgProtocol

// required uint32 player_id = 1;
inline bool RoomListMsgProtocol::has_player_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RoomListMsgProtocol::set_has_player_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RoomListMsgProtocol::clear_has_player_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RoomListMsgProtocol::clear_player_id() {
  player_id_ = 0u;
  clear_has_player_id();
}
inline ::google::protobuf::uint32 RoomListMsgProtocol::player_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.RoomListMsgProtocol.player_id)
  return player_id_;
}
inline void RoomListMsgProtocol::set_player_id(::google::protobuf::uint32 value) {
  set_has_player_id();
  player_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.RoomListMsgProtocol.player_id)
}

// repeated .gamer.protocol.RoomItemMsgProtocol room_list = 2;
inline int RoomListMsgProtocol::room_list_size() const {
  return room_list_.size();
}
inline void RoomListMsgProtocol::clear_room_list() {
  room_list_.Clear();
}
inline const ::gamer::protocol::RoomItemMsgProtocol& RoomListMsgProtocol::room_list(int index) const {
  // @@protoc_insertion_point(field_get:gamer.protocol.RoomListMsgProtocol.room_list)
  return room_list_.Get(index);
}
inline ::gamer::protocol::RoomItemMsgProtocol* RoomListMsgProtocol::mutable_room_list(int index) {
  // @@protoc_insertion_point(field_mutable:gamer.protocol.RoomListMsgProtocol.room_list)
  return room_list_.Mutable(index);
}
inline ::gamer::protocol::RoomItemMsgProtocol* RoomListMsgProtocol::add_room_list() {
  // @@protoc_insertion_point(field_add:gamer.protocol.RoomListMsgProtocol.room_list)
  return room_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::gamer::protocol::RoomItemMsgProtocol >&
RoomListMsgProtocol::room_list() const {
  // @@protoc_insertion_point(field_list:gamer.protocol.RoomListMsgProtocol.room_list)
  return room_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::gamer::protocol::RoomItemMsgProtocol >*
RoomListMsgProtocol::mutable_room_list() {
  // @@protoc_insertion_point(field_mutable_list:gamer.protocol.RoomListMsgProtocol.room_list)
  return &room_list_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace gamer

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_room_5flist_5fmsg_5fprotocol_2eproto__INCLUDED
